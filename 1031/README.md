# Git & GitHub

## 깃(Git) 개요

Git은 파일 변경 이력을 추적하고 관리하는 **분산 버전 관리 시스템**이다. 이를 통해 여러 개발자가 협업하면서 동일한 프로젝트를 안정적으로 관리할 수 있다.

### Git의 주요 기능

* 버전 관리: 수정 기록을 남기고 과거 버전으로 돌아갈 수 있음
* 백업: 저장소를 원격 서버(GitHub 등)에 보관 가능
* 협업: 여러 개발자가 동시에 작업 가능

---

## Git 저장소 구조

| 영역                | 설명                   |
| ----------------- | -------------------- |
| Working Directory | 실제 파일을 수정하는 디렉터리     |
| Staging Area      | 커밋할 파일을 임시로 선택해두는 공간 |
| Repository        | 커밋된 버전이 저장되는 공간      |

### 버전 생성 흐름

```
작업 → git add → git commit
```

---

## 주요 Git 명령어

| 명령어                 | 설명             |
| ------------------- | -------------- |
| git init            | Git 저장소 초기화    |
| git status          | 파일 상태 확인       |
| git add 파일명         | 스테이징 영역에 파일 추가 |
| git commit -m "메시지" | 버전 기록 생성       |
| git log --oneline   | 커밋 이력 확인       |

---

## 브랜치(Branch)

브랜치는 하나의 저장소에서 독립적인 작업 라인을 생성하는 방법이다.

### 브랜치 관련 주요 명령어

```
git branch             # 브랜치 목록 확인
git branch feature     # 새 브랜치 생성
git switch feature     # 브랜치 이동
git merge feature      # 브랜치 병합
```

### 브랜치 활용 전략

* main: 안정적인 배포 버전
* feature-* : 기능 개발 브랜치

---

## GitHub를 활용한 원격 저장소 관리

원격 저장소는 인터넷 상에 존재하는 Git 저장소이다.

| 명령어           | 설명              |
| ------------- | --------------- |
| git clone URL | 원격 저장소 복제       |
| git remote -v | 원격 저장소 연결 정보 조회 |
| git pull      | 원격 변경사항 가져옴     |
| git push      | 지역 변경사항 업로드     |

### GitHub를 사용하는 이유

* 백업 및 협업 용이
* 코드 리뷰 및 관리 기능 제공
* 온라인 개발 환경 지원(Codespaces 등)

---

## 협업 흐름 (Pull Request 기반)

1. 기능 개발용 브랜치 생성
2. 작업 완료 후 commit → push
3. GitHub에서 Pull Request 생성
4. 리뷰 및 승인 절차
5. main에 병합(merge)
6. 필요 시 브랜치 삭제

---

## 충돌(Conflict) 처리

동일 파일의 동일 부분을 각각 수정하면 충돌이 발생한다.
수정 후 충돌 표시 구문을 제거하고 원하는 내용만 남긴 뒤 다시 커밋한다.

---

## .gitignore 사용

Git으로 추적할 필요 없는 파일을 관리에서 제외한다.

```
node_modules/
*.exe
.env
```

---

## 실습 명령어 예시

```
# 파일 수정
git status

git add hello.txt
git commit -m "hello.txt 수정"
git push
```

---

## GitHub 추가 기능

* Codespaces: 온라인 IDE 환경 제공
* github.dev: 웹 기반 간단 편집기 (저장소에서 . 입력)
* Copilot: AI 기반 코드 작성 지원

---

## 정리

Git은 버전 및 브랜치 관리 도구이며, GitHub는 이를 기반으로 협업과 코드 리뷰 등 팀 프로젝트 환경을 제공한다.
원격 저장소를 통해 팀원들과 안정적으로 공동 개발할 수 있다.
