from queue import Queue


class SuffixTrieNode:
    def __init__(self, path, ch, par):
        self.path = path
        self.ch = ch
        self.par = par
        self.child = {}
        self.suff = None
        self.dict_suff = None
        self.leaf = False


class SuffixTrie:
    def __init__(self, words):
        self.root = SuffixTrieNode('', '', None)
        self.root.par = self.root
        self.root.suff = self.root
        self.root.dict_suff = self.root

        for word in words:
            self.add_word(word)
        self.build_suffixes()

        self.root.path = "{}"

    def add_word(self, word):
        cur = self.root
        for ch in word:
            if ch not in cur.child:
                cur.child[ch] = SuffixTrieNode(cur.path+ch, ch, cur)
            cur = cur.child[ch]
        cur.leaf = True

    def build_suffixes(self):
        q = Queue()
        for ch in self.root.child:
            q.put(self.root.child[ch])
            self.root.child[ch].suff = self.root
            self.root.child[ch].dict_suff = self.root
        while not q.empty():
            cur = q.get()
            for ch in cur.child:
                q.put(cur.child[ch])
                suffix = cur.suff
                while ch not in suffix.child and suffix != self.root:
                    suffix = suffix.suff
                cur.child[ch].suff = suffix.child[ch] if ch in suffix.child else self.root
                if cur.child[ch].suff.leaf:
                    cur.child[ch].dict_suff = cur.child[ch].suff
                else:
                    cur.child[ch].dict_suff = cur.child[ch].suff.dict_suff

    def _print(self, node, ind):
        pre = '  '*ind
        print(f"{pre} {node.path} {node.suff.path} {node.dict_suff.path} {node.leaf}")
        for ch in node.child:
            self._print(node.child[ch], ind+1)

    def print(self):
        self._print(self.root, 0)


def AhoCorasick(text, keywords):
    trie = SuffixTrie(keywords)
    state = trie.root
    out = []
    for i, ch in enumerate(text):
        while ch not in state.child and state != trie.root:
            state = state.suff
        state = state.child[ch] if ch in state.child else trie.root
        if state.leaf:
            out.append((state.path, i-len(state.path)+1))
        dict_suff = state.dict_suff
        while dict_suff != trie.root:
            out.append((dict_suff.path, i-len(dict_suff.path)+1))
            dict_suff = dict_suff.dict_suff
    return out


T = int(input())
for _t in range(T):
    S = input()
    N = int(input())
    subs = []
    for _n in range(N):
        subs.append(input())
    occs = AhoCorasick(S, subs)
    # print(occs)
    freq = {s: 0 for s in subs}
    for occ, pos in occs:
        freq[occ] += 1
    # print(freq)
    for sub in subs:
        print('y' if freq[sub] > 0 else 'n')