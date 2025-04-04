/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    int MaxLevel = 0;
    map<TreeNode *, int> NodeLevel;
    map<TreeNode *, TreeNode *> NodeParent;
    stack<pair<TreeNode *, int>> S;

    S.push(make_pair(root, 0));
    NodeParent[root] = root;
    while (!S.empty()) {
      auto [CurNode, CurLevel] = S.top();
      S.pop();
      NodeLevel[CurNode] = CurLevel;
      MaxLevel = max(MaxLevel, CurLevel);
      if (CurNode->left != nullptr) {
        NodeParent[CurNode->left] = CurNode;
        S.push(make_pair(CurNode->left, CurLevel + 1));
      }
      if (CurNode->right != nullptr) {
        NodeParent[CurNode->right] = CurNode;
        S.push(make_pair(CurNode->right, CurLevel + 1));
      }
    }

    vector<TreeNode *> DeepestLeaves;
    for (auto [CurNode, CurLevel] : NodeLevel) {
      if (CurLevel == MaxLevel) {
        DeepestLeaves.push_back(CurNode);
      }
    }

    while (true) {
      bool finished = true;
      for (auto CurNode : DeepestLeaves) {
        if (CurNode != DeepestLeaves[0]) {
          finished = false;
          break;
        }
      }
      if (finished)
        break;
      for (auto &CurNode : DeepestLeaves) {
        CurNode = NodeParent[CurNode];
      }
    }

    return DeepestLeaves[0];
  }
};
