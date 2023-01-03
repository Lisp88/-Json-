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
    skip_space();
    char ch = m_str[m_index];

    if(ch == '-' || std::isdigit(ch)) {
        return parse_number();
    }else if(ch == 'n') return parse_null();
    else if(ch == 't' || ch == 'f') return parse_bool();
    else if(ch == '"') return parse_string();
    else if(ch == '[') return parse_array();
    else if(ch == '{') return parse_object();

    throw std::logic_error("Parser::parse >> type non match");
}

char Parser::skip_space(){
    while(m_str[m_index] == ' ' || m_str[m_index] == '\n' || m_str[m_index] == '\r' || m_str[m_index] == '\t') ++m_index;
    return m_str[m_index];
}

char Parser::get_next_json(){
    skip_space();
    //return m_str[m_index++];
    return m_str[m_index];
}

Json Parser::parse_null() {
    if(m_str.compare(m_index, 4, "null") == 0) {
        m_index += 4;
        return Json();
    }
    throw std::logic_error("Parser::parse >> type non match");
}

Json Parser::parse_number() {
    int pos = m_index;
    int count = 0;
    if(m_str[m_index] == '-'){
        count++;
        m_index++;
    }

    bool is_double = false;
    while(m_str[m_index] == '.' || std::isalnum(m_str[m_index]) ){
        if(m_str[m_index++] == '.') is_double = true;
        ++count;
    }
    std::string number = m_str.substr(pos, count);
    if(is_double)
        return Json(std::stod(number));
    else
        return Json(std::stoi(number));
}

Json Parser::parse_bool() {
    if(m_str.compare(m_index, 4, "true") == 0){
        m_index += 4;
        return Json(true);
    }

    else if(m_str.compare(m_index, 5, "false") == 0){
        m_index += 5;
        return Json(false);
    }
    throw std::logic_error("Parser::parse >> type non match");
}

std::string Parser::parse_string() {
    std::string out;
    while(1){
        char ch = m_str[++m_index];
        if(ch == '"') break;
        //TODO
        // 处理转义字符
        //if(ch == '\\'){
        out += ch;
    }
    ++m_index;//脱离字符串，指向引号下一位
    return out;
}

Json Parser::parse_array() {
    Json arr(Json::json_array);
    ++m_index;
    char ch = skip_space();
    if(ch == ']') return arr;
    while(1){
        arr.append(parse());
        ch = skip_space();
        if(ch == ']') break;
        if(m_str[m_index++] != ',') throw std::logic_error("Parser :: parse_array >> ',' isn't exist");//++越过 ','
        ch = skip_space();
    }
    ++m_index;//越过数组范围，跳过']'
    return arr;
}

Json Parser::parse_object() {
    Json obj(Json::json_object);
    ++m_index;//越过'{'
    char ch = skip_space();
    if(ch == '}') return obj;
    while(1){
        if(ch != '"') throw std::logic_error("Parse::parse_object >> key type is error");
        std::string key = parse_string();
        ch = skip_space();
        if(ch != ':') throw std::logic_error("Parse::parse_object >>  ':' isn't exist");
        ++m_index;//越过 ':'
        obj[key] = parse();
        ch = skip_space();
        if(ch == '}') break;
        if(m_str[m_index++] != ',') throw std::logic_error("Parser :: parse_object >> ',' isn't exist");//++越过 ','
        ch = skip_space();
    }
    ++m_index;//越过'}'
    return obj;
}
