def do_intersect(line1, line2):
    """Check if two line segments (line1 and line2) intersect"""

    def orientation(A, B, C):
        """Return orientation of the triplet (A, B, C):
        0 -> Collinear
        1 -> Clockwise
        2 -> Counterclockwise
        """
        (x1, y1) = A
        (x2, y2) = B
        (x3, y3) = C

        val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2)
        if val == 0:
            return 0  # Collinear
        elif val > 0:
            return 1  # Clockwise
        else:
            return 2  # Counterclockwise

    def on_segment(A, B, C):
        """Check if point C lies on segment AB"""
        (x1, y1) = A
        (x2, y2) = B
        (x3, y3) = C

        return min(x1, x2) <= x3 <= max(x1, x2) and min(y1, y2) <= y3 <= max(y1, y2)

    A, B = line1
    C, D = line2

    # Find the four orientations needed for the straddling test
    o1 = orientation(A, B, C)
    o2 = orientation(A, B, D)
    o3 = orientation(C, D, A)
    o4 = orientation(C, D, B)

    # General case: the line segments straddle each other
    if o1 != o2 and o3 != o4:
        return True

    # Special Cases: Check if the points are collinear and lie on the segment
    # Case 1: A, B, C are collinear, and C lies on segment AB
    if o1 == 0 and on_segment(A, B, C):
        return True

    # Case 2: A, B, D are collinear, and D lies on segment AB
    if o2 == 0 and on_segment(A, B, D):
        return True

    # Case 3: C, D, A are collinear, and A lies on segment CD
    if o3 == 0 and on_segment(C, D, A):
        return True

    # Case 4: C, D, B are collinear, and B lies on segment CD
    if o4 == 0 and on_segment(C, D, B):
        return True

    return False


def check_line_segment_intersection(rtree, new_line):
    """Check if a new line segment intersects with any line in the R-tree"""
    # Step 1: Get the MBR of the new line segment
    mbr = rtree._calculate_mbr(new_line)

    # Step 2: Query the R-tree for possible intersections (MBRs that intersect)
    possible_intersections = rtree.search(mbr)

    # Step 3: For each retrieved line segment, check for actual intersection
    for line_segment in possible_intersections:
        if (
            do_intersect(new_line, line_segment)
            and new_line != line_segment
            and new_line[0] not in line_segment
            and new_line[1] not in line_segment
        ):
            print(f"Line {new_line} intersects with line {line_segment}")
            return [
                new_line,
                line_segment,
            ]  # Return as soon as an intersection is found

    return False  # No intersections found


class Node:
    def __init__(self, is_leaf=False):
        self.entries = []  # Each entry is (MBR, child/line_segment)
        self.is_leaf = is_leaf  # Whether this node is a leaf node


class RTree:
    def __init__(self, max_entries=4):
        self.root = Node(is_leaf=True)
        self.max_entries = max_entries

    def insert(self, line_segment):
        """Insert a line segment ((x1, y1), (x2, y2)) into the R-tree"""
        mbr = self._calculate_mbr(line_segment)
        leaf_node = self._choose_leaf(self.root, mbr)
        leaf_node.entries.append((mbr, line_segment))
        if len(leaf_node.entries) > self.max_entries:
            self._split_node(leaf_node)

    def _calculate_mbr(self, line_segment):
        """Calculate the MBR (minimum bounding rectangle) for a line segment"""
        (x1, y1), (x2, y2) = line_segment
        return (min(x1, x2), min(y1, y2)), (max(x1, x2), max(y1, y2))

    def _choose_leaf(self, node, mbr):
        """Choose the best leaf node for insertion"""
        if node.is_leaf:
            return node
        # Find the child whose MBR needs the least enlargement to include the new MBR
        best_child = None
        best_enlargement = float("inf")
        for child_mbr, child_node in node.entries:
            enlargement = self._calculate_enlargement(child_mbr, mbr)
            if enlargement < best_enlargement:
                best_enlargement = enlargement
                best_child = child_node
        return self._choose_leaf(best_child, mbr)

    def _calculate_enlargement(self, mbr1, mbr2):
        """Calculate how much MBR1 would need to be enlarged to include MBR2"""
        (min_x1, min_y1), (max_x1, max_y1) = mbr1
        (min_x2, min_y2), (max_x2, max_y2) = mbr2
        new_min_x = min(min_x1, min_x2)
        new_min_y = min(min_y1, min_y2)
        new_max_x = max(max_x1, max_x2)
        new_max_y = max(max_y1, max_y2)
        new_area = (new_max_x - new_min_x) * (new_max_y - new_min_y)
        old_area = (max_x1 - min_x1) * (max_y1 - min_y1)
        return new_area - old_area

    def _split_node(self, node):
        """Split a node if it exceeds the maximum number of entries"""
        # Simple split: divide the entries into two nodes
        entries = node.entries
        midpoint = len(entries) // 2
        node.entries = entries[:midpoint]
        new_node = Node(is_leaf=node.is_leaf)
        new_node.entries = entries[midpoint:]
        if node == self.root:
            new_root = Node()
            new_root.entries.append((self._get_mbr(node), node))
            new_root.entries.append((self._get_mbr(new_node), new_node))
            self.root = new_root
        else:
            # Re-insert the new node into the parent (simplified version)
            pass

    def _get_mbr(self, node):
        """Get the MBR of a node by combining the MBRs of all its entries"""
        min_x = min(entry[0][0][0] for entry in node.entries)
        min_y = min(entry[0][0][1] for entry in node.entries)
        max_x = max(entry[0][1][0] for entry in node.entries)
        max_y = max(entry[0][1][1] for entry in node.entries)
        return (min_x, min_y), (max_x, max_y)

    def search(self, query_rect):
        """Search for line segments within the given rectangular region"""
        return self._search_recursive(self.root, query_rect)

    def _search_recursive(self, node, query_rect):
        results = []
        for mbr, entry in node.entries:
            if self._intersects(mbr, query_rect):
                if node.is_leaf:
                    results.append(entry)  # Found a line segment
                else:
                    results.extend(self._search_recursive(entry, query_rect))
        return results

    def _intersects(self, mbr, query_rect):
        """Check if two rectangles (MBRs) intersect"""
        (min_x1, min_y1), (max_x1, max_y1) = mbr
        (min_x2, min_y2), (max_x2, max_y2) = query_rect
        return not (
            min_x1 > max_x2 or max_x1 < min_x2 or min_y1 > max_y2 or max_y1 < min_y2
        )


if __name__ == "__main__":

    # Example usage:
    rtree = RTree()
    # rtree.insert(((2, 3), (5, 7)))
    # rtree.insert(((6, 1), (9, 3)))
    # rtree.insert(((3, 8), (4, 10)))
    # rtree.insert(((5, 5), (8, 8)))

    lines = [[[0, 0], [0, 2]], [[0, 2], [-1, 2]], [[-1, 2], [-1, 1]], [[-1, 1], [1, 1]]]
    for line in lines:
        rtree.insert(line)

    # # Search for line segments within the rectangle (0, 0) to (6, 6)
    # results = rtree.search(((0, 0), (6, 6)))
    # print("Line segments in range:", results)

    intersections = []
    for line in lines:
        # Check if the new line intersects with any existing line in the R-tree
        result = check_line_segment_intersection(rtree, line)
        if result:
            A, B = result
            if A not in intersections:
                intersections.append(A)
            if B not in intersections:
                intersections.append(B)
    print("Intersections:", intersections)
