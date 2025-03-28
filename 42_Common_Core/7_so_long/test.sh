clean
clear
echo "\t" > SoLongTester.md
echo "# test.txt" >> SoLongTester.md; echo "\n" >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cd resources/LIBFT
make fclean
make
cd ../..
gcc -Wall -Wextra -Werror **/**.c resources/LIBFT/libft.a -o so_long_test
# gcc -Wall -Wextra -Werror -fsanitize=address *.c
cd resources/LIBFT
make fclean
cd ../..
echo "\n\n" >> SoLongTester.md
./so_long_test test.txt >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md


echo "\t" >> SoLongTester.md
echo "# level_0.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_0.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_0.ber >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

echo "\t" >> SoLongTester.md
echo "# level_1.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_1.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_1_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_1_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_1_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_1_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_1_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_4.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_1_4.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_5.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_1_5.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_1_6.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_1_6.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

echo "\t" >> SoLongTester.md
echo "# level_2.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_2.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_2_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_2_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_2_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_2_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_2_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_2_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_2_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_2_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

echo "\t" >> SoLongTester.md
echo "# level_3.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_3.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_3.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

echo "\t" >> SoLongTester.md
echo "# level_4.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_4.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_4_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_4_0.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_4_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_4_1.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
cat maps/level_4_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
./so_long_test maps/level_4_2.ber >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md


echo "\t" >> SoLongTester.md
echo "# level_5.ber" >> SoLongTester.md
echo "\n" >> SoLongTester.md
cat maps/level_5.txt >> SoLongTester.md
echo "\n" >> SoLongTester.md
echo level_5.bEr >> SoLongTester.md
echo "\n" >> SoLongTester.md
./so_long_test maps/level_5.bEr >> SoLongTester.md
echo "\n" >> SoLongTester.md
echo level_5.md >> SoLongTester.md
echo "\n" >> SoLongTester.md
./so_long_test maps/level_5md >> SoLongTester.md
echo "\n" >> SoLongTester.md
echo level_5.ver >> SoLongTester.md
echo "\n" >> SoLongTester.md
./so_long_test maps/level_5.ver >> SoLongTester.md
echo "\n\n" >> SoLongTester.md
echo "\n________________________________________________________________________________________________________________________________________\n\n\n" >> SoLongTester.md

rm -rf so_long_test
rm -rf a.out
cd resources/LIBFT; make fclean; cd ../..
clean
clear
