#pragma once

namespace morris_traversal {

template<typename Node, typename F>
void MorrisTraversal(Node *node, F callback)
{
    Node *curr = node;
    Node *prev = node;

    while (curr != nullptr)
    {
        // we've gotten all the way to the left, so go right
        if (curr->Left() == nullptr) {
            callback(curr->Data());
            curr = curr->Right();
        } else {
            // go to the left once, then down on the right
            prev = curr->Left();
            while (prev->Right() != nullptr && prev->Right() != curr)
            {
                prev = prev->Right();
            }

            // hold onto the top of where we started this iteration
            // by attaching it to prev->right, then keep going left
            if (prev->Right() == nullptr) {
                prev->SetRight(curr);
                curr = curr->Left();
            // loop back to the top of where we started this iteration
            } else {
                prev->SetRight(nullptr);
                callback(curr->Data());
                curr = curr->Right();
            }
        }
    }
}

} // namespace morris_traversal
