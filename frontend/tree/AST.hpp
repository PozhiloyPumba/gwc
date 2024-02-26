#ifndef __AST_HPP__
#define __AST_HPP__

#include <vector>

namespace GWC {

template <typename T> class AST final {
    T root_;

    // TODO: Maybe check existing interface for dump...
    void printNodeIntoGraphviz(T curNode, std::ostream &out) const {
        out << "\"" << curNode << "\" [label = \"";
        curNode->dump(out);
        out << "\"]\n";

        for (auto it = curNode->childs_.begin(); it != curNode->childs_.end();
             ++it) {
            T curChild = *it;
            if (curChild)
                printNodeIntoGraphviz(curChild, out);
        }
    }

    void buildConnectionsInGraphviz(T curNode, std::ostream &out) const {
        for (auto it = curNode->childs_.begin(); it != curNode->childs_.end();
             ++it) {
            T curChild = *it;
            if (curChild)
                out << "\"" << curNode << "\" -> \"" << curChild << "\"\n";
        }

        for (auto it = curNode->childs_.begin(); it != curNode->childs_.end();
             ++it) {
            T curChild = *it;
            if (curChild)
                buildConnectionsInGraphviz(curChild, out);
        }
    }

public:
    void setRoot(T root) { root_ = root; }
    T getRoot() const { return root_; }

    void dumpTree(std::ostream &out) const {
        if (!root_)
            return;

        out << "digraph tree {\n"
               "rankdir = \"LR\"\n"
               "node [fontsize=10, shape=box, height=0.5]\n"
               "edge [fontsize=10]\n";

        printNodeIntoGraphviz(root_, out);
        buildConnectionsInGraphviz(root_, out);

        out << "}\n";
    }
};

} // namespace GWC

#endif