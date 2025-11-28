# Unreal Engine 5 Beginner Guide

---

## 1. Installation & Setup

### ✔ Epic Games Launcher 설치
- Epic Games Launcher 다운로드 및 로그인
- `Unreal Engine → Library → Install`
- Option 메뉴에서 필요한 구성 요소 선택 후 설치

### ✔ 프로젝트 생성
- `Launch` 클릭 후 템플릿 선택 (예: Third Person, First Person)
- 프로젝트 이름, 저장 경로 설정 후 생성

---

## 2. Unreal Engine 인터페이스 구성

| UI 영역 | 설명 |
|--------|------|
| **Viewport** | 오브젝트 배치 및 씬 미리보기 |
| **Outliner** | 씬에 배치된 객체 계층 구조 |
| **Details Panel** | 선택한 객체의 속성 수정 |
| **Content Browser** | 애셋, Blueprint, 머티리얼 등 관리 |
| **Toolbar** | 저장, 실행(Play), 빌드 기능 |
| **Actor Placement Panel** | 큐브, 빛, 카메라 등 기본 요소 배치 |

---

## 3. 기본 조작 단축키

| 기능 | 단축키 |
|------|--------|
| 선택 (Select Mode) | `Q` |
| 이동 (Translate) | `W` |
| 회전 (Rotate) | `E` |
| 크기 조절 (Scale) | `R` |
| Viewport 카메라 이동 | 마우스 우클릭 + `WASD` |
| Snap 설정 변경 | Toolbar Snap 옵션 |


---

## 4. Level 생성 및 환경 구성

### ✔ Level 생성
- `Content Browser → 우클릭 → Level → Save`

### ✔ 환경 요소 추가
Environment Light Mixer 또는 Actor Placement 사용:

| 구성 요소 | 역할 |
|-----------|------|
| **Directional Light** | 태양광 |
| **Sky Light** | 간접광 (GI) |
| **Sky Atmosphere** | 하늘/대기 효과 |
| **Volumetric Cloud** | 실시간 구름 |
| **Exponential Height Fog** | 거리 기반 안개 표현 |

---

## 5. Blueprint 시스템

### ✔ Blueprint 유형

| 유형 | 용도 |
|------|------|
| **Level Blueprint** | 특정 레벨 전용 스크립트 |
| **Blueprint Class (Actor/Pawn 등)** | 재사용 가능한 객체 기반 논리 |

### ✔ Blueprint Editor 구성
- Event Graph: 실행 로직
- Variables / Events / Functions: 데이터 및 흐름
- Details Panel: 노드/컴포넌트 속성 수정

### ✔ 예제: 키 입력 → 텍스트 출력

1. `Input Action` 생성  
2. `Input Mapping Context(IMC)`에 등록  
3. Blueprint Event Graph에서 `Print String`으로 연결  

---

## 6. Character Movement 구조 (Third Person Template)

- 방향 입력: `Add Movement Input`
- 마우스 회전: `Add Controller Pitch/Yaw`
- 점프: Input Action → Jump Function 호출

---

## 7. C++ Actor Programming

### ✔ 개발 환경 준비
- Visual Studio 설치
- **C++ Game Development** Workload 포함
- UE → `Open in Visual Studio`

### ✔ 핵심 함수

| 함수 | 기능 |
|------|------|
| `BeginPlay()` | 객체 생성 후 최초 1회 실행 |
| `Tick(float DeltaTime)` | 프레임마다 반복 실행 |

### ✔ 화면 출력 예제

```cpp
#include "MyActor.h"
#include "Engine/Engine.h"

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("Hello Unreal!"));
    }
}
