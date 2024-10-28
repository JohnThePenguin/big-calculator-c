def convert_decimal_to_base(number: int, base: int) -> str:
    if number == 0:
        return "0"
    
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    result = ""
    number = number
    
    while number > 0:
        remainder = number % base
        result = digits[remainder] + result
        number //= base
    
    
    return result

a = input("")
b = input("")
print(convert_decimal_to_base(int(a), int(b)))
