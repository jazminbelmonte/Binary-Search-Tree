#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_











/* PART 1: implemenation */
template <typename T>
struct Node {
  T info;
  Node *llink;
  Node *rlink;
  Node(): llink(nullptr), rlink(nullptr) {}
  Node(T info) : info(info), llink(nullptr), rlink(nullptr) {}
};

template <typename T>
class BinarySearchTree {
public:
  BinarySearchTree() : root(nullptr) {}
  BinarySearchTree(const BinarySearchTree<T> &bt) { copy(root, bt.root); }
  BinarySearchTree<T> &operator=(BinarySearchTree<T> &bt){
    if (this != &bt) {
      destroy(root);
      copy(root, bt.root);
    }

    return *this;
  }

  bool empty() const { return root == nullptr; }

  /* Returns how many nodes in the longest path between the root and a child */
  int height() const { return height(root); }
  int height(const Node<T> *node) const {
    if (node != nullptr){
      return 0;
    } else {
      return 1 + max(height(node->llink), height(node->rlink));
    }
  }

  //to help height function
  int max(int x, int y) const {
    if (x >= y)
      return x;
    else
      return y;
  }

  /* Returns how many links between nodes it takes to get to node from the root */
  int level(T e) const{
    //TODO
  } 

  /* Returns the node with the minimum value */
  const Node<T>* minimum() const{ return minimum(root); }
  const Node<T>* minimum(Node<T>* node) const{
    //TODO
  }

  /* Returns the node with the maximum value */
  const Node<T>* maximum() const { return maximum(root); }
  const Node<T>* maximum(Node<T>* node) const {
    //TODO
  }

  /* Returns how many node in a tree */
  int size() const { return size(root); }
  int size(const Node<T>* node) const {
    if(node){
      return 1 + size(node->llink) + size(node->rlink);
    }else {
      return 0;
    }
  }

  /* Returns how many leaf nodes (nodes without children) in the tree */
  int leavesCount() const { return leavesCount(root); }
  int leavesCount(const Node<T>* node) const{
    if(node){
      if(!node->llink && !node->rlink){
        return 1;
      }else{
        return leavesCount(node->llink) + leavesCount(node->rlink);
      }
    } else {
      return 0;
    }
  }

  /* Puts the nodes of the tree into an array in ascending or descending order */
  void toSortedArray(Node<T>* &array, bool reversed = false){
    //TODO
  }

  /* Implements inorder traversal */
  void inorderTraversal(void (*showFunc)(const Node<T>*, int)) const { inorderTraversal(showFunc, root, 0); }
  void inorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const{
    if(node){
      inorderTraversal(showFunc, node->llink, depth + 1);
      showFunc(node, depth);
      inorderTraversal(showFunc, node->rlink, depth + 1);
    }
  }

   /* Implements preorder traversal */
  void preorderTraversal(void (*showFunc)(const Node<T>*, int)) const { preorderTraversal(showFunc, root, 0); }
  void preorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const {
    if (node){
      showFunc(node, depth);
      preorderTraversal(showFunc, node->llink, depth + 1);
      preorderTraversal(showFunc, node->rlink, depth + 1);
    }
  }

   /* Implements postorder traversal */
  void postorderTraversal(void (*showFunc)(const Node<T>*, int)) const { postorderTraversal(showFunc, root, 0); }
  void postorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const {
    if(node){
      postorderTraversal(showFunc, node->llink, depth + 1);
      postorderTraversal(showFunc, node->rlink, depth + 1);
      showFunc(node, depth);
    }
  }

  /* Returns true if e was found */
  const Node<T>* search(T e) const{
    //TODO
  }  

  /* Returns true if e was successfully inserted */
  bool insert(T e){
    if(root){
      auto current = root;
      Node<T>* beforeCurrent = nullptr;
      while(current){
        beforeCurrent = current;
        if(current->info == e){
          return false; // Element is already in the list
        }else if(e < current->info){
          current = current->llink;
        }else if(e > current->info){
          current = current->rlink;
        }
      }

      if(e < beforeCurrent->info){
        beforeCurrent->llink = new Node<T>(e);
      }else{
        beforeCurrent->rlink = new Node<T>(e);
      }
    } else {
      root = new Node<T>(e);
    }
    return true;
  } 

  bool remove(T e){
    return remove(root, e);
  }
  
  /* Returns true if e was successfully deleted */
  bool remove(Node<T>* &node, T e){
    if(node){
      if(e < node->info){
        return remove(node->llink, e);
      }else if(e > node->info){
        return remove(node->rlink, e);
      }else if(node->llink && node->rlink) {// Two children
        node->info = maximum(node->llink)->info;
        return remove(node->llink, node->info);
      }else{
        Node<T> *temp = node;
        node  = (node->llink ) ? node->llink : node->rlink;
        delete temp;
        return true;
      }
    }

    return false;
  }

  ~BinarySearchTree(){ destroy(root); }
  
private:
  Node<T> *root;
  void destroy(Node<T> *node) {
    if (node){
      destroy(node->llink);
      destroy(node->rlink);

      delete node;
      node = nullptr;
    }
  }
  void copy(Node<T> *&dest, const Node<T> *src) {
    if (src){
      dest = new Node<T>(src->info);
      copy(dest->llink, src->llink);
      copy(dest->rlink, src->rlink);
    } else {
      dest = nullptr;
    }
  }
};













/* PART 2: Tree-traversal functions */
template <typename T> 
void showTree(const Node<T>* node, int depth){
  //TODO
}
#endif