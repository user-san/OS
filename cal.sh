read -p "Enter n1: " n1
read -p "Enter n2: " n2

echo "Enter:
1- Add
2- Subtract
3- Multiply
4- Divide"

read -p "Enter your choice: " ch

case $ch in
    1) echo "Sum: $((n1 + n2))" ;;
    2) echo "Difference: $((n1 - n2))" ;;
    3) echo "Product: $((n1 * n2))" ;;
    4) 
        if [ $n2 -eq 0 ]; then
            echo "Error: Division by zero is not allowed"
        else
            echo "Quotient: $((n1 / n2))"
        fi
        ;;
    *) echo "Invalid choice" ;;
esac
