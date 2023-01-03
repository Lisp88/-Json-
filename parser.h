//
// Created by Shota on 2022/12/30.
//

#ifndef JSON_STUDY_PARSER_H
#define JSON_STUDY_PARSER_H

#include "string"
#include "json.h"

namespace shotacon{
    namespace json{
        class Parser{
        public:
            Parser();

            void load(const std::string & str);

            Json parse();
        private:
            Json parse_null();
            Json parse_number();
            Json parse_bool();
            std::string parse_string();
            Json parse_array();
            Json parse_object();

            char skip_space();

            char get_next_json();
        private:
            std::string m_str;
            int m_index;
        };
    }
}
#endif //JSON_STUDY_PARSER_H
