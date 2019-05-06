import java.util.*
// 5014번 스타트링크
// 분류: 큐
// 문제:
//      엘리베이터를 U칸만 올라가고 D칸만 내려갈 수 있을 때
//      최소 몇번 눌러야 전체 F층인 건물 S층에서 G층으로 갈수 있는지 구하라
// 풀이:
//      현재층과 누른 횟수를 queue에 넣고 하나씩 빼면서 다음
//      도착층을 검사해 나가면 최소 횟수일 때의 원하는 층에 도착하는지 검사 가능하다.
//      BFS와 같은 원리
//      문제 풀 때 .add를 안쓰고 .push를 쓰니 앞에 들어가서 자꾸 틀렸다.
fun main() {
    // e[0] = 총 층, e[1] = 초기 층, e[2] = 목적 층
    // e[3] = 올라가는 층 e[4] = 내려가는 층
    val e = readLine()!!.split(" ").map { it.toInt() }

    val q = ArrayDeque<Pair<Int, Int>>()
    val visit = Array(1000002){ false }

    q.push(Pair(e[1], 0))
    visit[e[1]] = true

    var isAnswer = false

    while(q.isNotEmpty()) {
        val now = q.poll()

        if(now.first == e[2]) {
            isAnswer = true
            println(now.second)
            break
        }

        if(e[3] != 0 && now.first + e[3] <= e[0] && !visit[now.first + e[3]]) {
            q.add(Pair(now.first + e[3], now.second + 1))
            visit[now.first + e[3]] = true
        }
        if(e[4] != 0 && now.first - e[4] > 0 && !visit[now.first - e[4]]) {
            q.add(Pair(now.first - e[4], now.second + 1))
            visit[now.first - e[4]] = true
        }
    }
    if(!isAnswer)
        println("use the stairs")
}
