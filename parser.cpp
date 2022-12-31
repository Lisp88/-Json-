//
// Created by Shota on 2022/12/30.
//

#include "parser.h"

using namespace shotacon::json;

Parser::Parser() : m_str(""), m_index(0){

}

void Parser::load(const std::string & str){
    m_str = str;
    m_index = 0;
}

Json Parser::parse() {
    char ch = get_token_then_next();

    if(ch == '-' || std::isalnum(ch)) {
        return parse_number();
    }else if(ch == 'n') return parse_null();
    else if(ch == 't' || ch == 'f') return parse_bool();
    else if(ch == '"') return parse_string();
    else if(ch == '[') return parse_array();
    else if(ch == '{') return parse_object();

    throw std::logic_error("Parser::parse >> type non match");
}

void Parser::skip_space(){
    while(m_str[m_index] == ' ' || m_str[m_index] == '\n' || m_str[m_index] == '\r' || m_str[m_index] == '\t') ++m_index;
}

char Parser::get_token_then_next(){
    skip_space();
    //return m_str[m_index++];
    return m_str[m_index];
}

Json Parser::parse_null() {
    if(m_str.compare(m_index, 4, "null") == 0)
    return Json();
    throw std::logic_error("Parser::parse >> type non match");
}

Json Parser::parse_number() {
    int pos = m_index;
    if(m_str[m_index] == '-') m_index++;
    bool is_double = false;
    while(m_str[m_index] == '.' || std::isalnum(m_str[m_index]) ){
        if(m_str[m_index] == '.') is_double = true;
        ++m_index;
    }
    std::string number = m_str.substr(pos, m_index);
    if(is_double)
        return Json(std::stod(number));
    else
        return Json(std::stoi(number));
}

Json Parser::parse_bool() {
    if(m_str.compare(m_index, 4, "true") == 0)
        return Json(true);
    else if(m_str.compare(m_index, 5, "false") == 0)
        return Json(false);
    throw std::logic_error("Parser::parse >> type non match");
}

std::string Parser::parse_string() {
    return std::string();
}

Json Parser::parse_array() {
    return Json();
}

Json Parser::parse_object() {
    return Json();
}
