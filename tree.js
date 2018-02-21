function Node(data, left = null, right = null) {
  this.data = data;
  this.left = left;
  this.right = right;
}

function Tree() {
  this.root = null;
}

Tree.prototype.add = function(data) {
  if (this.root === null) {
    this.root = new Node(data);
    return;
  } else {
    const searchTree = function(node) {
      if (data < node.data) {
        if (node.left === null) {
          const node = new Node(data);
          node.left = node;
          return;
        } else if (node.left !== null) {
          return searchTree(node.left);
        }
      } else if (data > node.data) {
        if (node.right === null) {
          const node = new Node(data);
          node.right = node;
          return;
        } else if (node.right !== null) {
          return searchTree(node.right);
        }
      } else return null;
    };
    searchTree(this.root);
  }
};

const bst = new Tree();

bst.add(5);
console.log(bst.root.data);

bst.add(6);
bst.add(7);
bst.add(8);
bst.add(1);
bst.add(2);
bst.add(3);

console.log(bst.left.data);
