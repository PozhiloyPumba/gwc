#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <string>
#include <unordered_map>
#include <vector>

namespace GWC {

struct Node {
    Node *parent_;
    std::vector<Node *> childs_;

    enum class Type {
        COND,
        CYCLE,
        BINOP,
        UNOP,
        FUNC,
        VAR,
        ARRAY,
        NOOP,
        GRAPHIC,
        TYPE,
        NUMBER
    };
    Type initType;
    Node(Type type) : initType(type) {}
    virtual void dump(std::ostream &out) const = 0;
};

struct BinOpNode : public Node {
    enum class BinOp_Type {
        ADD,
        SUB,
        MUL,
        DIV,
        OR,
        NEQ,
        LTE,

        ASSIGN
    };
    BinOp_Type binOpType;

    BinOpNode(BinOp_Type type) : Node(Type::BINOP), binOpType(type) {}

    void dump(std::ostream &out) const override {
        switch (binOpType) {
        case BinOp_Type::ADD:
            out << "ADD" << std::endl;
            break;
        case BinOp_Type::SUB:
            out << "SUB" << std::endl;
            break;
        case BinOp_Type::MUL:
            out << "MUL" << std::endl;
            break;
        case BinOp_Type::DIV:
            out << "DIV" << std::endl;
            break;
        case BinOp_Type::OR:
            out << "OR" << std::endl;
            break;
        case BinOp_Type::NEQ:
            out << "NEQ" << std::endl;
            break;
        case BinOp_Type::LTE:
            out << "LTE" << std::endl;
            break;
        case BinOp_Type::ASSIGN:
            out << "ASSIGN" << std::endl;
            break;
        default:;
        }
    }
};

struct CondNode : public Node {
    enum class Cond_Type { IF };
    Cond_Type condType;

    CondNode(Cond_Type type = Cond_Type::IF)
        : Node(Type::COND), condType(type) {}

    void dump(std::ostream &out) const override { out << "IF" << std::endl; }
};

struct CycleNode : public Node {
    enum class Cycle_Type { WHILE, FOR, RANGE_FOR };
    Cycle_Type cycleType;

    CycleNode(Cycle_Type type) : Node(Type::CYCLE), cycleType(type) {}

    void dump(std::ostream &out) const override {
        switch (cycleType) {
        case Cycle_Type::FOR:
            out << "FOR" << std::endl;
            break;
        case Cycle_Type::WHILE:
            out << "WHILE" << std::endl;
            break;
        case Cycle_Type::RANGE_FOR:
            out << "RANGE_FOR" << std::endl;
            break;
        default:;
        }
    }
};
struct FuncNode : public Node {
    enum class Func_Type { FUNC_DECL, FUNC_ARGS };
    Func_Type funcType;
    std::string name;

    FuncNode(Func_Type type, const std::string &id)
        : Node(Type::FUNC), funcType(type), name(id) {}
    void dump(std::ostream &out) const override {
        switch (funcType) {
        case Func_Type::FUNC_DECL:
            out << "FUNC_DECL: " << name << std::endl;
            break;
        default:;
        }
    }
};

struct GraphicNode : public Node {
    enum class Graphic_Type { SET_PIXEL, UPDATE_GPU_BUFFER, FLUSH };
    Graphic_Type graphicType;

    GraphicNode(Graphic_Type type) : Node(Type::GRAPHIC), graphicType(type) {}

    void dump(std::ostream &out) const override {
        switch (graphicType) {
        case Graphic_Type::SET_PIXEL:
            out << "SET_PIXEL" << std::endl;
            break;
        case Graphic_Type::UPDATE_GPU_BUFFER:
            out << "UPDATE_GPU_BUFFER" << std::endl;
            break;
        case Graphic_Type::FLUSH:
            out << "FLUSH" << std::endl;
            break;
        default:;
        }
    }
};

struct ArrayNode : public Node {
    std::vector<int> sizes;
    std::string name;

    ArrayNode(const std::string &id) : Node(Type::ARRAY), name(id) {}

    void dump(std::ostream &out) const override {
        out << "ARRAY: " << name << std::endl;
        out << "size:";
        for (auto &s : sizes)
            out << " " << s;
        out << std::endl;
    }
};

struct VarNode : public Node {
    std::string name;

    VarNode(const std::string &id) : Node(Type::VAR), name(id) {}
    void dump(std::ostream &out) const override {
        out << "ID: " << name << std::endl;
    }
};

struct NumNode : public Node {
    int value;

    NumNode(int v) : Node(Type::NUMBER), value(v) {}
    void dump(std::ostream &out) const override {
        out << "NUMBER: " << value << std::endl;
    }
};

struct TypeNode : public Node {
    enum class VarType { I8, I32 };

    const std::unordered_map<std::string, VarType> names_ = {
        std::pair{"i8", VarType::I8}, std::pair{"i32", VarType::I32}};

    VarType type;
    TypeNode(const std::string &typeName) : Node(Type::TYPE) {
        auto it = names_.find(typeName);
        if (it == names_.end())
            throw std::runtime_error("INVALID TYPE: \"" + typeName + "\"");
        type = it->second;
    }

    void dump(std::ostream &out) const override {
        out << "TYPE: " << std::endl;
        switch (type) {
        case VarType::I8:
            out << "i8" << std::endl;
            break;
        case VarType::I32:
            out << "i32" << std::endl;
            break;
        default:;
        }
    }
};

struct UnOpNode : public Node {
    enum class UnOp_Type { UNARY_MINUS, NOT, RETURN };
    UnOp_Type unOpType;

    UnOpNode(UnOp_Type type) : Node(Type::UNOP), unOpType(type) {}

    void dump(std::ostream &out) const override {
        switch (unOpType) {
        case UnOp_Type::UNARY_MINUS:
            out << "UNARY_MINUS" << std::endl;
            break;
        case UnOp_Type::RETURN:
            out << "RETURN" << std::endl;
            break;
        case UnOp_Type::NOT:
            out << "NOT" << std::endl;
            break;
        default:;
        }
    }
};

struct NoOpNode : public Node {
    enum class NoOp_Type { CONTINUE, SCOPE, LIST };

    NoOp_Type noOpType;
    NoOpNode(NoOp_Type type) : Node(Type::NOOP), noOpType(type) {}

    void dump(std::ostream &out) const override {
        switch (noOpType) {
        case NoOp_Type::CONTINUE:
            out << "CONTINUE" << std::endl;
            break;
        case NoOp_Type::SCOPE:
            out << "SCOPE" << std::endl;
            break;
        case NoOp_Type::LIST:
            out << "LIST" << std::endl;
            break;
        default:;
        }
    }
};

} // namespace GWC

#endif