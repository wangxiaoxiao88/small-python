## small-python

### 介绍
基于[Python源码剖析](http://book.douban.com/subject/3117898/)第6章内容编写。实现了Python语言的的PyIntObject、PyStringObject和
PyDictObject对象，实现了加法操作和输出操作。

### Usage
* `git clone git@github.com:wangxiaoxiao88/small-python.git` 下载源码
* `make` 编译
* `./small-python` 运行

### Examples

    >>> a = 1
    >>> b = 2
    >>> c = a+b
    >>> print c
    3
    >>> a = "hi,"
    >>> b = "wangxx"
    >>> c = a+b
    >>> print c
    hi,wangxx
