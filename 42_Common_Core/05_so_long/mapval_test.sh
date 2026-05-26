clean
clear
echo "\t" > SoLongTester.md
echo "# test.txt" >> SoLongTester.md; echo "\n" >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
norminette header_file > norminette.txt
norminette resources > norminette.txt
norminette sources > norminette.txt
make
# gcc -w1 -Wextra -Werror -fsanitize=address *.c
echo "\n\n" >> SoLongTester.md
./so_long test.txt >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md


echo "\t" >> SoLongTester.md
echo "# level_0.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_0.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_0.ber >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

echo "\t" >> SoLongTester.md
echo "# level_1.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_1.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_1_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_1_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_1_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_1_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_1_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_4.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_1_4.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_5.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_1_5.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./game_test.sh maps/level_1_5.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_6.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_1_6.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./game_test.sh maps/level_1_6.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

echo "\t" >> SoLongTester.md
echo "# level_2.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_2.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_2_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_2_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_2_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_2_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_2_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_2_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_2_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_2_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./game_test.sh maps/level_2_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

echo "\t" >> SoLongTester.md
echo "# level_3.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_3.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

echo "\t" >> SoLongTester.md
echo "# level_4.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_4.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_4_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_4_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_4_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_4_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./game_test.sh maps/level_4_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_4_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long maps/level_4_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./game_test.sh maps/level_4_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md


echo "\t" >> SoLongTester.md
echo "# level_5.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_5.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
echo level_5.bEr >> SoLongTester.md
echo "\n" >> SoLongTester.md
./so_long maps/level_5.bEr >> SoLongTester.md
echo "\n" >> SoLongTester.md
echo level_5.md >> SoLongTester.md
echo "\n" >> SoLongTester.md
./so_long maps/level_5md >> SoLongTester.md
echo "\n" >> SoLongTester.md
echo level_5.ver >> SoLongTester.md
echo "\n" >> SoLongTester.md
./so_long maps/level_5.ver >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

rm -rf so_long_test
rm -rf a.out
make fclean
open norminette.txt
open SoLongTester.md
clean
#clear
