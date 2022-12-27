//
// Created by Shota on 2022/12/27.
//
#include "json.h"

using namespace shotacon::json;

//构造函数
Json::Json() : m_type(json_null) {}

Json::Json(bool v) : m_type(json_bool) {
    m_value.m_bool = v;
}

Json::Json(int v) : m_type(json_int) {
    m_value.m_int = v;
}

Json::Json(double v) : m_type(json_double) {
    m_value.m_double = v;
}

Json::Json(const char *v) : m_type(json_string) {

    m_value.mp_string = new std::string(v);
}

Json::Json(const std::string &v) {
    m_value.mp_string = new std::string(v);
}

Json::Json(json_type type) {
    switch (type) {
        case json_null:
            break;
        case json_bool:
            m_value.m_bool = false;
            break;
        case json_int:
            m_value.m_int = 0;
            break;
        case json_double:
            m_value.m_double = 0.0;
            break;
        case json_string:
            m_value.mp_string = new std::string;
            break;
        case json_array:
            m_value.mp_array = new std::vector<Json>;
            break;
        case json_object:
            m_value.mp_object = new std::map<std::string, Json>;
            break;
        default:
            break;
    }
}

//拷贝构造，对于数组，对象和字符串进行浅拷贝提升效率
Json::Json(const Json &v) {
    json_type type = v.m_type;
    switch (type) {
        case json_null:
            break;
        case json_bool:
            m_value.m_bool = v.m_value.m_bool;
            break;
        case json_int:
            m_value.m_int = v.m_value.m_int;
            break;
        case json_double:
            m_value.m_double = v.m_value.m_double;
            break;
        case json_string:
            m_value.mp_string = v.m_value.mp_string;
            break;
        case json_array:
            m_value.mp_array = v.m_value.mp_array;
            break;
        case json_object:
            m_value.mp_object = v.m_value.mp_object;
            break;
        default:
            break;
    }
}

Json::operator bool() {
    if (m_type != json_bool) {
        throw std::logic_error("type error, not bool type");
    }
    return m_value.m_bool;
}

Json::operator int() {
    if (m_type != json_int) {
        throw std::logic_error("type error, not int type");
    }
    return m_value.m_int;
}

Json::operator double() {
    if (m_type != json_double) {
        throw std::logic_error("type error, not double type");
    }
    return m_value.m_double;
}

Json::operator std::string() {
    if (m_type != json_string) {
        throw std::logic_error("type error, not string type");
    }
    return *(m_value.mp_string);
}

Json::operator const char *() {
    if (m_type != json_string) {
        throw std::logic_error("type error, not string type");
    }
    return m_value.mp_string->c_str();
}