# -Json-
自己实现一个Json库，用于Json格式的解析，速度较快，直接拿json.cpp和json.h就能使用
## Json解析库简介
该Json解析库支持将Json格式的字符串解析为Json对象。

**优点 ：**
* 速度快：该库Json的字符串，数组及对象的存储采用指针。方法支持深浅拷贝，默认的赋值为浅拷贝。所以在执行拷贝操作时比一般用深拷贝的json库快大约一般的时间。

**缺点 ：**
* 易出错：由于为浅拷贝，所以在编写Json时要注意及时释放Json对象，以防造成内存泄露。并且要注意对象的内存控制不要误释放内存导致野/null指针的访问
## 代码结构
* 代码总共分为两个模块，一个为Json模块，主要负责Json对象的封装构建；一个Parser模块，主要负责将字符串解析为Json对象。
### Json
1. **成员属性 :**  核心部分就是构造Json对象，内部有两个成员变量，一个是通过枚举来决定存放的数据类型；第二个就是存放的数据内容，对于字符串，数组和对象类型采用指针存储。
2. **构造以及运算符重载 ：** 运用隐式构造转换，支持其他类型在赋值时转化为Json类型；运用重载的对象类型转换来支持Json赋值转化为别的类型。
3. **常用方法 :** 
    * append ： 传入Json对象，当Json为数组时对Json数组进行扩充。
    * get : 返回string，可以用来打印Json内容
    * parse ： 传入Json格式字符串进行解析
    * shallow/deep _copy :浅\深拷贝
    * clear() : 清空Json对象内容
    * size : 返回Json内数据数量
    * has : 传入数组下标或者key，查看是否合法
    * remove ：传入下标或key删除元素（删除的内存自动释放）
    * is_xxx(type) : 判断Json数据的类型，例 : is_null, is_double
### Parser
1. **成员属性 ：** 一个是字符串，存放解析的Json格式字符串；另一个为int类型的下标
2. **常用方法 :**
    * load : 传入字符串，拷贝到成员变量内
    * parse : 对成员变量内的字符串进行解析
    
**测试图片**
* 测试代码
![测试代码](https://github.com/Laity8/picture_resource_resort/blob/master/json_repository/code_test.png)
* 运行结果
![运行结果](https://github.com/Laity8/picture_resource_resort/blob/master/json_repository/run_result.png)
