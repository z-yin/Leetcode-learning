import numpy as np
import pandas as pd


class DecisionTree:
    def __init__(self, df, method='C4.5', eps=0.01):
        self.df = pd.DataFrame(df)
        self.eps = eps
        self.method = method
        self.tree = self.create_tree(self.df)

    def entropy(self, count):
        p = count / count.sum()
        p = p[p != 0]
        return -p.dot(np.log2(p))

    def conditional_entropy(self, cb):
        w = cb.sum(1) / cb.to_numpy().sum()
        HDi = cb.apply(self.entropy, 'columns')
        return w.dot(HDi)

    def weight_entropy(self, cbs):
        w = [cb.sum(1) / cb.to_numpy().sum() for cb in cbs]
        enpy = [-i.dot(np.log2(i)) for i in w]
        return np.array(enpy)

    def split_data(self, df):
        labels = df.iloc[:, -1]
        data = df.iloc[:, :-1]
        # calculate HD
        ck = labels.groupby(labels).count()
        HD = self.entropy(ck)
        # calculate HDA
        cbs = [pd.crosstab(data.iloc[:, i], labels)
               for i in range(data.columns.size)]
        HDA = np.array([self.conditional_entropy(cb) for cb in cbs])
        if self.method == 'ID3':
            g = HD - HDA
        elif self.method == 'C4.5':
            # calculate HAD, not HDA
            HAD = self.weight_entropy(cbs)
            g = np.ndarray(shape=HAD.shape)
            np.divide((HD - HDA), HAD, g)
        # if largest gain is less than eps
        if g.max() < self.eps:
            return labels.mode().iloc[0]
        split_index = g.argmax()
        name = df.columns[split_index]
        children = df.groupby(df.iloc[:, split_index])
        return ((name, i, d.drop(name, axis=1)) for i, d in children)

    def create_tree(self, df):
        if df.iloc[:, -1].unique().size == 1:  # single class
            return df.iloc[0, -1]
        if df.columns.size == 1:  # A = empty
            return df.mode().iloc[0, 0]

        sub_df = self.split_data(df)
        # if largest gain is less than eps
        if isinstance(sub_df, str):
            return sub_df
        # if largest gain is larger than eps
        res = {}
        for name, i, d in sub_df:
            if name not in res:
                res[name] = {}
            res[name][i] = self.create_tree(d)
        return res


if __name__ == "__main__":
    d = pd.read_csv('your.txt')
    dt = DecisionTree(d, 'ID3')
    print(dt.tree)
