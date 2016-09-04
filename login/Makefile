CC = gcc
pkg=`pkg-config --cflags --libs gtk+-2.0`

all:login2 entry_example  nested_table vbox hpaned combo_spinbutton_glist\
check_radio menu_example
.PHONY:all


login2:login.c
	$(CC) -o login2 login.c $(pkg)
entry_example:entry_example.c
	$(CC) -o entry_example entry_example.c $(pkg)
nested_table:nested_table.c
	$(CC) -o nested_table nested_table.c $(pkg)
vbox:vbox.c
	$(CC) -o vbox vbox.c $(pkg)
hpaned:hpaned.c
	$(CC) -o hpaned hpaned.c $(pkg)
combo_spinbutton_glist:combo_spinbutton_glist.c
	$(CC) -o combo_spinbutton_glist combo_spinbutton_glist.c $(pkg)
menu_example:menu_example.c
	$(CC) -o menu_example menu_example.c $(pkg)
# 测试多行注释\
我也是注释测试多行注释

check_radio:check_radio.c
	$(CC) -o check_radio check_radio.c $(pkg)
.PHONY:clean
clean:
	rm login2  entry_example vbox  nested_table hpaned combo_spinbutton_glist\
check_radio menu_example
