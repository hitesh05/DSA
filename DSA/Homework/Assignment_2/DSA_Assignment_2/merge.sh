cat bst.h > a2.c
echo >> a2.c
sed '/#include "bst.h"/d' ./utils.h >> a2.c
echo >> a2.c
sed '/include/d' ./main.c >> a2.c
echo >> a2.c
sed '/include/d' ./bst.c >> a2.c
echo >> a2.c
sed '/include/d' ./utils.c >> a2.c