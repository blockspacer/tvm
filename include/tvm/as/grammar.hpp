//
// Created by Mehmet Fatih BAKIR on 27/04/2018.
//

#pragma once

#include <tvm/as/token.hpp>
#include <tvm/as/tokens.hpp>
#include <variant.hpp>
#include <vector>
#include <tuple>
#include <string>

namespace tvm::as
{
    template <class... Ts>
    using sum = mpark::variant<Ts...>;

    template <class T>
    using many = std::vector<T>;

    template <class... Ts>
    using prod = std::tuple<Ts...>;

    struct int_lit {
        token t;

        uint64_t val;
    };

    struct float_lit {
        token t;

        double val;
    };
    struct string_lit {
        token t;

        std::string val;
    };

    struct label {
        token t;

        std::string name;
    };
    struct register_ {
        token t;

        std::string name;
    };

    struct name {
        token t;

        std::string name;
    };

    struct blk_comment {
        token t;
    };

    struct line_comment {
        token t;
    };

    using literal = sum<int_lit, float_lit>;
    using operand = sum<literal, label, register_>;
    using operands = many<operand>;
    using instruction = prod<name, operands>;

    using entity = sum<instruction, blk_comment, line_comment>;

    using program = many<entity>;
}