import numpy as np
import heapq


class Node:
    def __init__(self, data, dim, left=None, right=None):
        self.data = data
        self.dim = dim
        self.left = left
        self.right = right

    def __str__(self):
        return str(self.data)

    __repr__ = __str__


class KNN:
    def __init__(self, data):
        total_dim = data.shape[1]

        def create(dataset, dim):
            if len(dataset) == 0:
                return None
            # sort the dataset based on current dimension
            dataset = sorted(dataset, key=lambda x: x[dim])
            mid = len(dataset) // 2  # middle element
            return Node(dataset[mid], dim, \
                        # split the data equally to left and right children
                        create(dataset[:mid], (dim + 1) % total_dim), \
                        create(dataset[mid + 1:], (dim + 1) % total_dim))

        self.kd_tree = create(data, 0)

    def k_nearest_neighbors(self, x, n_neighbors=5, p=2):
        self.knn = [(-np.inf, None)] * n_neighbors

        def visit(node):
            if node:
                # distance from x to hyperplane of node
                dis_to_plane = x[node.dim] - node.data[node.dim]
                # decide which child to visit next
                visit(node.left if dis_to_plane < 0 else node.right)
                # distance from x to node itself
                dis_to_node = np.linalg.norm(x - node.data, p)
                # push current node to heapq and pop the one with largest distance
                heapq.heappushpop(self.knn, (-dis_to_node, node))
                # check if nearest neighbors are in the adjacent area
                if (-self.knn[0][0] > abs(dis_to_plane)):
                    visit(node.right if dis_to_plane < 0 else node.left)

        visit(self.kd_tree)
        self.knn = np.array(
            [i[1] for i in heapq.nlargest(n_neighbors, self.knn)])
        return self.knn


if __name__ == "__main__":
    X = np.array([[0, 0], [1, 1], [2, 2], [3, 3]])
    knnc = KNN(X)
    knnc.k_nearest_neighbors(np.array((1.4, 1.4)), 2)
    print(knnc.knn)
