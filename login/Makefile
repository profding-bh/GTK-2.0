CC = gcc
pkg=`pkg-config --cflags --libs gtk+-2.0`

# 测试多行注释\
我也是注释测试多行注释

# phony target
all:login2 entry_example  nested_table vbox hpaned combo_spinbutton_glist\
 check_radio menu_example signal_example ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8
.PHONY:all clean

# targets
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
signal_example:signal_example.c
	$(CC) -o signal_example signal_example.c $(pkg)
check_radio:check_radio.c
	$(CC) -o check_radio check_radio.c $(pkg)
ex1:ex1.c
	$(CC) -o ex1 ex1.c $(pkg)
ex2:ex2.c
	$(CC) -o ex2 ex2.c $(pkg)
ex3:ex3.c
	$(CC) -o ex3 ex3.c $(pkg)
ex4:ex4.c
	$(CC) -o ex4 ex4.c $(pkg)
ex5:ex5.c
	$(CC) -o ex5 ex5.c $(pkg)
ex6:ex6.c
	$(CC) -o ex6 ex6.c $(pkg)
ex7:ex7.c
	$(CC) -o ex7 ex7.c $(pkg)
ex8:ex8.c
	$(CC) -o ex8 ex8.c $(pkg)
clean:
	rm login2  entry_example vbox  nested_table hpaned combo_spinbutton_glist\
 check_radio menu_example signal_example ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8
