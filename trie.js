function Node() {
  this.keys = new Map();
  this.end = false;

  this.setEnd = function() {
    this.end = true;
  };

  this.isEnd = function() {
    return this.end;
  };
}

function Trie() {
  this.root = new Node();
  this.add = function(input, node = this.root) {
    if (input.length === 0) {
      node.setEnd();
      return;
    } else if (node.keys.has(input[0])) {
      return this.add(input.substr(1), node.keys.get(input[0]));
    } else {
      node.keys.set(input[0], new Node());
      return this.add(input.substr(1), node.keys.get(input[0]));
    }
  };

  this.search = function(word, node = this.root) {
    if (!node.keys.has(word[0])) {
      return false;
    } else {
      while (word.length > 1) {
        if (node.keys.has(word[0])) {
          node = node.keys.get(word[0]);
          word = word.substr(1);
        } else {
          return false;
        }
      }
      return node.keys.has(word) && node.keys.get(word).isEnd() ? true : false;
    }
  };

  this.print = function(fromNode = this.root) {
    let words = new Array();
    let search = function(node, string) {
      if (node.keys.size !== 0) {
        for (let letter of node.keys.keys()) {
          search(node.keys.get(letter), string.concat(letter));
        }
        if (node.isEnd()) {
          words.push(string);
        }
      } else string.length > 0 ? words.push(string) : undefined;
    };
    search(fromNode, new String(""));
    return words;
  };

  this.suggest = function(word) {
    let findEnd = function(node, keyword) {
      if (keyword.length > 1 && node.keys.has(keyword[0])) {
        return findEnd(node.keys.get(keyword[0]), keyword.substr(1));
      } else if (keyword.length === 1 && node.keys.has(keyword)) {
        return node.keys.get(keyword);
      } else {
        return null;
      }
    };
    const endNode = findEnd(this.root, word);
    const sugg = this.print(endNode);
    return sugg;
  };
}

const myTrie = new Trie();

myTrie.add("web");
myTrie.add("webdev");
myTrie.add("webart");
console.log(myTrie.search("web"));
const node = myTrie.suggest("web");
console.log(node);
// FIXME: prevent adding empty string
