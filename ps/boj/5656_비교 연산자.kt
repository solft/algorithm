
// 5656번 비교 연산자
// 분류: eval
// 문제:
//      문자열로 주어진 식이 참인지 거짓인지 판별하는 문제
// 풀이:
//      case 나눠서 풀었는데 함수형으로 풀 수 도 있을 것 같다.
fun main() {
    var case = 1
    while(true){
        val expression = readLine()!!.split(" ")
        if(expression[1] == "E")
            break

        when {
            expression[1] == ">" -> {
                if(expression[0].toInt() > expression[2].toInt())
                    println("Case ${case++}: true")
                else
                    println("Case ${case++}: false")
            }
            expression[1] == ">=" -> {
                if(expression[0].toInt() >= expression[2].toInt())
                    println("Case ${case++}: true")
                else
                    println("Case ${case++}: false")
            }
            expression[1] == "<" -> {
                if(expression[0].toInt() < expression[2].toInt())
                    println("Case ${case++}: true")
                else
                    println("Case ${case++}: false")
            }
            expression[1] == "<=" -> {
                if(expression[0].toInt() <= expression[2].toInt())
                    println("Case ${case++}: true")
                else
                    println("Case ${case++}: false")
            }
            expression[1] == "==" -> {
                if(expression[0].toInt() == expression[2].toInt())
                    println("Case ${case++}: true")
                else
                    println("Case ${case++}: false")
            }
            expression[1] == "!=" -> {
                if(expression[0].toInt() != expression[2].toInt())
                    println("Case ${case++}: true")
                else
                    println("Case ${case++}: false")
            }
        }
    }
}
