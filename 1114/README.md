# Unity 기능 정리

---

## 1. 에디터 UI 관련 기능

### Hierarchy
- 씬 내 존재하는 모든 오브젝트 목록
- 오브젝트 생성, 복제, 삭제, 이름 변경, 부모-자식 구조 설정 가능

### Inspector
- 선택된 오브젝트의 구성 요소(Component) 확인 및 속성 수정
- Transform, 컴포넌트 값, Material 지정 등 모든 설정 변경 지점

### Scene View / Game View
- **Scene View:** 개발자가 씬을 조작하고 배치하는 공간  
- **Game View:** 실제 플레이어 관점의 결과 화면 확인

### Transform (Position / Rotation / Scale)
- 오브젝트의 위치, 회전, 크기를 제어하는 기본 속성

---

## 2. 렌더링 및 시각 표현 기능

### Material
- 오브젝트의 색상, 질감, 텍스처를 설정하는 데이터
- `Albedo`, `Metallic`, `Smoothness` 등 시각 표현 요소 포함

### Shader 적용 기반 표현
- Material과 연결되어 오브젝트의 렌더링 방식을 결정

---

## 3. 3D 오브젝트 및 공간 구성

### 기본 오브젝트 생성(3D Object)
- Cube, Sphere, Plane 등 기본 형태를 배치하여 씬 구성

### Terrain 시스템
- 대규모 지형 생성
- 브러시를 이용한 조형, 텍스처 페인팅 지원

---

## 4. 물리 시스템 기능

### Rigidbody
- 오브젝트에 물리 속성(중력, 질량, 속도) 적용
- 물리 연산 기반 움직임 처리

### Collider
- 충돌 판정 처리 (BoxCollider, SphereCollider 등 다양한 형태 존재)
- 물리 반응은 Rigidbody가 있어야 가능

### Physics Material
- 마찰력, 탄성 등을 설정하여 충돌 시 반응 제어(Bounciness 등)

---

## 5. 게임플레이 조작 관련 기능

### Input System
- 키보드·마우스 입력 감지
- `Input.GetAxis()` / `Input.GetButton()` 등 입력 기반 동작 처리

### CharacterController
- 물리 기반이 아닌 **코드 기반 이동 및 충돌 처리용 컴포넌트**
- 캐릭터 이동, 점프 등 제어에 적합

---

## 6. 애니메이션 시스템 기능

### Animator
- 애니메이션 상태를 전환하고 재생하는 시스템
- 애니메이션 트리(State Machine) 구성

### Animation Parameters
- Speed, Trigger 같은 파라미터로 스크립트와 애니메이션 연결

---

## 7. 스크립팅 및 컴포넌트 기반 구조

### C# Script 연결
- `MonoBehaviour` 기반으로 코드 작성
- Update(), Start(), FixedUpdate() 등 게임 루프와 연결

### Component 시스템
- 모든 기능은 오브젝트에 컴포넌트 형태로 추가되고 결합됨
- "속성을 가진 컴포넌트를 조합해서 기능을 완성하는 구조"

---

## 8. 프로젝트 & 에셋 관리 기능

### Assets 시스템
- 모델, 스크립트, 텍스처, 사운드 등 리소스를 저장 및 재사용
- 외부 패키지 Import 가능

### Prefab
- *(예제엔 안 쓰였지만 기능 개념상 중요해서 포함)*
- 오브젝트를 재사용 가능한 템플릿 형태로 저장

---

## 핵심 개념 요약

Unity의 구조는 **오브젝트 + 컴포넌트 + 스크립트 + 에셋 조립 방식**이며,  
에디터에서 배치한 후 스크립트와 입력·물리·애니메이션 시스템을 연결해  
게임 동작을 구현한다.

---

