# 보물찾기 게임 개선 정리

## 1. 개선 목적
- 게임 가독성 향상  
- 사용자 경험 증가  
- 맵과 플레이어 이동 좌표 불일치 해결
- 제한 시간 및 이동 횟수 기능 추가  
- 게임 종료 및 결과 표시 기능 추가  

---

## 2. 변경 사항 요약

| 구분 | 원본 코드 | 개선 코드 | 변경 내용 요약 |
|------|------------|------------|----------------|
| 보물 생성 | `tx[i] = rand() % map_x + 1;`<br>`ty[i] = rand() % map_y + 1;` | 중복 검사 루프 추가 | 동일 좌표 보물 방지 |
| 시간 제한 | 단순 `clock_t` 변수 선언만 있음 | 실시간 경과 시간 계산 | 제한 시간 초과 시 자동 종료 |
| 이동 제한 | 기능 없음 | 이동 횟수 카운트 및 제한 추가 | 정해진 이동 횟수 초과 시 게임 종료 |
| 화면 표시 | 출력 시 잔여 출력물 누적 | 매 턴 `system("cls")` 후 새로 그림 | 가독성 향상 |
| 종료 처리 | 없음 | 시간/이동 소진 시 메시지 출력 | 명확한 게임 종료 처리 |

---

## 3. 주요 변경 코드

### (1) 보물 중복 생성 방지

```c
// 기존
tx[i] = rand() % map_x + 1;
ty[i] = rand() % map_y + 1;

// 개선
do {
    tx[i] = rand() % map_x + 1;
    ty[i] = rand() % map_y + 1;
    duplicate = 0;
    for (j = 0; j < i; j++) {
        if (tx[i] == tx[j] && ty[i] == ty[j]) {
            duplicate = 1;
            break;
        }
    }
} while (duplicate);
```

> **변경 이유:** 보물 좌표 중복과 고정된 보물 개수 문제 해결

---

### (2) 제한 시간 기능 개선

```c
// 기존
clock_t start, end;
double pst;

// 개선
clock_t start = clock();
double elapsed = 0;

while (!gameover) {
    elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
    if (elapsed >= limit_time) {
        time_over = 1;
        break;
    }
}
```

> **변경 이유:** `clock()`을 이용한 실시간 경과 시간 측정으로  
> 제한 시간 초과 시 자동으로 종료 가능

---

### (3) 이동 횟수 제한 기능 추가

```c
int move_count = 0;

while (!gameover) {
    if (move_count >= limit_move) {
        printf("이동 횟수를 모두 소모했습니다.\n");
        break;
    }
    key = getch();
    move_count++;
}
```

> **변경 이유:** 게임 난이도 조절을 위해 이동 횟수 제한 기능 추가

---

### (4) 화면 갱신 및 가독성 개선

```c
// 기존
printf("█");

// 개선
system("cls");
basic_map(map_x, map_y);
display_map(matrix, tx, ty, map_x, map_y);
```

> **변경 이유:** 한 화면에 정보가 누적되어 보이던 문제 해결,  
> 매 턴마다 맵을 새로 그려서 가독성 향상

---

### (5) 게임 종료 처리 개선

```c
if (time_over) {
    printf("\n제한 시간이 초과되었습니다.\n");
} else if (move_count >= limit_move) {
    printf("\n이동 횟수를 모두 사용했습니다.\n");
} else {
    printf("\n모든 보물을 찾았습니다!\n");
}
```

> **변경 이유:** 종료 조건별 메시지 추가로 게임 결과를 명확히 전달

---

## 4. 개선 효과 요약

- **안정성 향상:** 중복 보물 문제 제거  
- **가독성 향상:** 화면 갱신 구조 정비  
- **게임성 향상:** 보물 개수 설정, 제한 시간, 이동 제한 기능 추가  
- **유지보수 용이:** 기능별 코드 블록 명확화
