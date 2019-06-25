
// 15239번 Password check
// 분류: 문자열
// 문제:
//      문자열에 소문자, 대문자, 기호, 숫자를 포함하고
//      12자 이상인지를 검사하는 문제
// 풀이:
//      길이는 입력 받은 n 으로 확인하고
//      문자는 set 으로 만들어 존재하는지 확인하고
//      나머지는 코틀린의 .is~~를 이용해서 풀었다.
fun main() {
    val symbolSet = setOf('+','_',')','(','*','&','^','%','$','#','@','!','.','/',',',';','{','}')
    val t = readLine()!!.toInt()
    for (i in 1 .. t){
        val n = readLine()!!.toInt()
        val password = readLine()!!
        var lowercase = false
        var uppercase = false
        var digit = false
        var symbol = false
        var length = false

        if(n >= 12 )
            length = true

        if(!length){
            println("invalid")
            continue
        }

        for (c in password){
            if (c in symbolSet)
                symbol = true
            else if(c.isDigit())
                digit = true
            else if(c.isLowerCase())
                lowercase = true
            else if(c.isUpperCase())
                uppercase = true

            if(lowercase && uppercase && digit && symbol)
                break
        }

        if(lowercase && uppercase && digit && symbol && length)
            println("valid")
        else
            println("invalid")
    }
}
