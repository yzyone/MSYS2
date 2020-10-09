# 所有包含Makefile的子目录都加到这里

#注意这里先编库
SUBDIRS = src/fun
#最后编程序，因为程序要依赖库
SUBDIRS += src


BIN_PATH = ./bin

# 定义一个函数,遍历所有的$(SUBDIRS), $1是参数
define make_subdir
@for i in $(SUBDIRS); do\
(cd $$i && make $1) \
done;
endef


# 默认的目标为编译所有子目录
ALL:
	$(shell if ! test -d $(BIN_PATH); then mkdir $(BIN_PATH); fi;)
	$(call make_subdir)

# 清空所有子目录
clean:
	$(shell if test -d $(BIN_PATH); then rm -rf $(BIN_PATH); fi;)
	$(call make_subdir, clean)

# 把子目录里生成的程序或so都拷到$(BIN_PATH)目录下
install:
	$(shell if ! test -d $(BIN_PATH); then mkdir $(BIN_PATH); fi;)
	$(call make_subdir, install)