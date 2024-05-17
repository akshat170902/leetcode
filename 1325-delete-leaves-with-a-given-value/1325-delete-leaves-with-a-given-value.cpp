class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<TreeNode*> stack;
        TreeNode* currentNode = root, *lastRightNode = nullptr;

        while (!stack.empty() || currentNode != nullptr) {
            // Push left nodes to the stack until reaching the leftmost node.
            while (currentNode != nullptr) {
                stack.push(currentNode);
                currentNode = currentNode->left;
            }

            // Access the top node on the stack without removing it.
            // This node is the current candidate for processing.
            currentNode = stack.top();

            // Check if the current node has an unexplored right subtree.
            // If so, shift to the right subtree unless it's the subtree we just visited.
            if (currentNode->right != lastRightNode && currentNode->right) {
                currentNode = currentNode->right;
                continue; // Continue in the while loop to push this new subtree's leftmost nodes.
            }

            // Remove the node from the stack, since we're about to process it.
            stack.pop();

            // If the node has no right subtree or the right subtree has already been visited,
            // then check if it is a leaf node with the target value.
            if (currentNode->right == nullptr && currentNode->left == nullptr && currentNode->val == target) {
                // If the stack is empty after popping, it means the root was a target leaf node.
                if (stack.empty()) {
                    return nullptr; // The tree becomes empty as the root itself is removed.
                }
                
                // Identify the parent of the current node.
                TreeNode* parent = stack.top();

                // Disconnect the current node from its parent.
                if (parent->left == currentNode) {
                    parent->left = nullptr; // If current node is a left child, set the left pointer to null.
                } else {
                    parent->right = nullptr; // If current node  is a right child, set the right pointer to null.
                }
            }

            // Mark this node as visited by setting 'lastRightNode' to 'currentNode' before moving to the next iteration.
            lastRightNode = currentNode;
            // Reset 'currentNode' to null to ensure the next node from the stack is processed.
            currentNode = nullptr;
        }
        return root; // Return the modified tree.
    }
};