 find . -name "*.c" | xargs cat 2>/dev/null | tr -s -c "a-zA-Z" "\n" | sort | uniq -c | sort -n -r | head -n 10  
 awk -F : -v sum=0 'BEGIN {printf("%s\n", "Begin")} {if ($3 >= 1000) {printf("%s\n", $3);sum+=$3;}} END{printf("Bye\n sum = %d\n", sum)}' /etc/passwd 
