// 2755번 이번학기 평점은 몇점?
// 분류: 구현, 반올림
// 문제:
//      평균 평점 구하는 문제
// 풀이:
//      그냥 구현하고 소수점 3자리에서 반올림후 2자리까지 표시하는 법 체크
fun score(a: String):Double {
    when(a){
        "A+" -> return 4.3
        "A0" -> return 4.0
        "A-" -> return 3.7

        "B+" -> return 3.3
        "B0" -> return 3.0
        "B-" -> return 2.7

        "C+" -> return 2.3
        "C0" -> return 2.0
        "C-" -> return 1.7

        "D+" -> return 1.3
        "D0" -> return 1.0
        "D-" -> return 0.7

        "F" -> return 0.0
    }
    return 0.0
}

fun main() {
    val n = readLine()!!.toInt()
    var sum = 0.0
    var div = 0.0
    for(i in 0 until n){
        val subject = readLine()!!.split(" ")
        sum += subject[1].toDouble() * score(subject[2])
        div += subject[1].toDouble()
    }
    println(String.format("%.2f", sum/div))
}
