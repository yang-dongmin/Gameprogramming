# 장애물 런 게임

Unity를 이용해 제작한 3D 러닝 게임입니다.  
플레이어가 장애물을 피하면서 스테이지를 따라 전진하고, 목표 지점에 도달하면 결과 화면이 표시됩니다.

## 주요 기능

- ThirdPersonController를 이용한 플레이어 캐릭터 이동
- MultipurposeCameraRig을 이용한 3인칭 카메라 추적
- Prototyping 프리팹(Floor, Cube 등)을 이용한 스테이지 구성
  - 여러 구간으로 나뉜 바닥(Floor1 ~ Floor4)
  - 양쪽 벽(Wall1, Wall2)과 장식용 오브젝트(Pillar)
  - Block1 ~ Block5 장애물 배치
- Metal 텍스처를 이용한 바닥, 벽, 장애물, 배경 오브젝트의 재질 설정
- Directional Light, Spot Light, Point Light를 이용한 조명 연출
- 배경 음악 재생
  - Pillar 오브젝트에 Audio Source를 추가하여 반복 재생
- 낙하 판정 영역(OutArea)
  - 큰 Cube에 Box Collider를 Is Trigger로 설정
  - Out 스크립트로 플레이어가 영역 밖으로 떨어졌는지 판정
- 목표 지점(GoalArea)
  - GoalArea Cube에 Box Collider를 Is Trigger로 설정
  - GoalArea 스크립트로 도달 여부 판정
- UI를 이용한 게임 시간 표시 및 결과 출력
  - TimeText: 현재 진행 시간 표시 (Timer 스크립트)
  - ResultTitle, ResultTimeText, BestTimeText, RetryButton을 하나의 Result 오브젝트 하위에 배치
  - GameResult 스크립트에서
    - 도달 시간, 최고 기록 시간 관리
    - Result 오브젝트 활성/비활성 제어
    - Retry 버튼 클릭 시 OnRetry 메서드 실행

## 사용 스크립트

- Out.cs  
- GoalArea.cs  
- Timer.cs  
- GameResult.cs  

---

# 공 굴리기 게임 (C# 스크립트 입문)

Unity와 C# 스크립트를 학습하기 위해 제작한 공 굴리기 형태의 실습 프로젝트입니다.  
Rigidbody, Collider, Material, UI, Prefab, 충돌 처리, 상속 등 Unity 기본 기능을 단계적으로 연습합니다.

## 주요 기능

- 스테이지 구성
  - Cube로 Ground 생성 후 회전 및 스케일 조정
  - Material을 만들어 Ground 색상 지정
- 공(Ball) 생성 및 물리 적용
  - Sphere + Rigidbody 추가
  - Physic Material(BallBounce)을 이용해 탄성 부여
- 위치 및 거리 출력
  - PrtPosition 스크립트로 시작 위치와의 거리 출력
  - if / else if를 사용하여 특정 구간마다 다른 메시지 출력
  - bool 변수를 사용해 특정 구간 메시지를 한 번만 출력
- Collider와 속성 변경
  - RadiusChange 스크립트로 SphereCollider의 radius를 계속 변경
- 카메라 따라가기
  - CameraFollow 스크립트에서 GameObject.Find("Ball")로 공을 찾고
  - 공의 위치를 기준으로 카메라 위치를 갱신
- 바닥 기울이기
  - GroundMove 스크립트에서
    - 키보드 입력(Input.GetAxis("Horizontal"))으로 바닥을 좌우 회전
    - 이후 마우스/터치 입력을 이용한 제어 기능 추가
- 점프 기능
  - BallJump 스크립트
  - Space 키 입력 시 Rigidbody.AddForce를 이용해 위로 힘을 가해 점프
- 장애물 이동
  - Cylinder로 Obstacle 생성
  - ObstacleMove 스크립트에서 delta 값을 이용해 좌우 반복 이동
  - localPosition을 사용하여 Stage 하위에서 상대 위치로 이동
- 충돌 처리
  - ObstacleMove의 OnCollisionEnter에서
    - 충돌한 오브젝트 이름 확인
    - 두 오브젝트 위치 차이로 방향 벡터를 계산한 후 AddForce로 튕겨냄
- 낙하 판정 및 재시작
  - Ground를 복제하여 FailZone 생성
  - Box Collider를 Is Trigger로 설정
  - FailZone 스크립트에서 OnTriggerEnter로 공이 떨어졌는지 판정
  - SceneManager.LoadScene(0)으로 씬을 다시 로드하여 게임 재시작
- 코인 획득
  - Cylinder를 얇게 만들어 Coin 생성
  - Capsule Collider Is Trigger 설정
  - CoinTrigger 스크립트에서 Ball과 충돌 시 Destroy(gameObject)로 코인 제거
  - 여러 코인에 Tag "Coin"을 설정하여 배열로 관리
- 태그 활용
  - GameObject.FindGameObjectsWithTag("Coin")으로 모든 코인 찾기
  - Obstacle에도 "Obstacle" 태그를 설정하여 일괄 제어에 사용
- RedCoin 아이템
  - 일반 코인과 색만 다른 RedCoin 생성
  - RedCoinItem 스크립트에서
    - Ball과 충돌 시 장애물 태그("Obstacle")를 가진 오브젝트를 모두 찾아서 Destroy
- GameManager를 통한 게임 관리
  - GameManager 스크립트에서
    - RestartGame(): 씬 재시작
    - RedCoinStart(): 장애물 제거
    - DestroyObstacles(): 태그 "Obstacle" 전체 삭제
    - coinCount 필드와 GetCoin()으로 코인 개수 관리
  - FailZone, RedCoinItem, CoinTrigger에서 GameManager 메서드를 호출
  - public 메서드/필드를 사용해 다른 스크립트에서 접근
- 코인 개수 UI 표시
  - TextMeshProUGUI를 이용하여 획득한 코인 개수를 화면에 표시
  - GameManager의 public TextMeshProUGUI coinText 필드에 UI 객체 연결
- Stone 발사체
  - Cube로 Stone 생성 후 스크립트 추가
  - Stone 스크립트에서
    - Start()에서 Ball 위치를 target으로 저장
    - Update()에서 Vector3.MoveTowards로 target 방향으로 이동
    - OnTriggerEnter에서 Ball과 충돌 시 GameManager.RestartGame 호출
- Shooter(발사 오브젝트)
  - 기존 Obstacle을 Shooter로 변경
  - Shooter 스크립트에서
    - timeCount와 Time.deltaTime을 이용하여 일정 시간 간격 측정
    - 간격이 지나면 Instantiate로 Stone Prefab 생성
  - Shooter가 ObstacleMove를 상속받아 장애물 이동 로직 재사용

## 사용 스크립트

- PrtPosition.cs  
- RadiusChange.cs  
- CameraFollow.cs  
- GroundMove.cs  
- BallJump.cs  
- ObstacleMove.cs  
- FailZone.cs  
- CoinTrigger.cs  
- RedCoinItem.cs  
- GameManager.cs  
- Stone.cs  
- Shooter.cs  



