//
// Created by Shota on 2022/12/27.
//

//宏定义隔离头文件，防止同一编译单元包含多个相同文件导致名字冲突（无法防止链接期的重定义错误）
#ifndef JSON_STUDY_JSON_H
#define JSON_STUDY_JSON_H

#include "vector"
#include "iostream"
//#include "unordered_map"
#include "memory"
#include "string"
#include "stdexcept"
#include "sstream"
#include "map"

namespace shotacon {
    namespace json {
        class Json {
        public:
            //用枚举定义json内的基本数据类型
            enum json_type {
                json_null = 0,
                json_bool,
                json_int,
                json_double,
                json_string,
                json_array,
                json_object
            };

            //默认构造函数
            Json();

            //构造函数中的 隐式转换构造 （可以在定义时用=，等号右边为参数，自动转换为类对象）
            Json(bool v);

            Json(int v);

            Json(double v);

            Json(const char *v);

            Json(const std::string &v);

            Json(json_type type);//自定义json的类型

            ~Json(){

            }

            //拷贝构造
            Json(const Json &v);

            //运算符重载中的 对象类型转换 无返回值 返回类型必须和重载类型相同，支持Json类型自动转化为其他类型
            operator bool();

            operator int();

            operator double();

            operator const char *();

            operator std::string();

            Json &operator[](int index);

            Json &operator[](const char *key);

            Json &operator[](const std::string &key);

            void operator = (const Json & j);

            bool operator == (const Json & j);

            bool operator != (const Json & j);

            //方法
            void append(const Json &other);

            std::string get() const;

            void shallow_copy(const Json &j);

            void deep_copy(const Json &j);

            void clear();

            int size() const;

            bool is_null() const { return m_type == json_null;}
            bool is_bool() const { return m_type == json_bool;}
            bool is_int() const { return m_type == json_int;}
            bool is_double() const { return m_type == json_double;}
            bool is_string() const { return m_type == json_string;}
            bool is_array() const { return m_type == json_array;}
            bool is_object() const { return m_type == json_object;}

            bool has(int index) const;
            bool has(const char * key) const;
            bool has(const std::string & key) const;

            bool remove(int index) const;
            bool remove(const char * key) const;
            bool remove(const std::string & key) const;
        private:
            union json_value {
                bool m_bool;
                int m_int;
                double m_double;
                std::string *mp_string;//非基本类型使用指针固定内存字节
                std::vector<Json> *mp_array;
                std::map<std::string, Json> *mp_object;
            };
            json_type m_type;
            json_value m_value;
        };
    }
}

#endif

