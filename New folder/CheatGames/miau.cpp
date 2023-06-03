#include "miau.h"
#include "Print.hpp"
#include "d3d9_x.h"
#include "xor.hpp"
#include "callspoof.h"
#include <dwmapi.h>
#include <vector>
#include "Keybind.h"
#include "offsets.h"
#include "xstring"
#include "controller.h"
#include "icons1.h"
#include "auth.hpp"
#include "Auth.h"
#include "json.hpp"
Memory* KmDrv = nullptr;

#define VK_W  	0x57
#define VK_A         	0x57
#define VK_S          0x53
#define VK_D 	0x44

DWORD64 bonearray;
#define color1 (WORD)(0x0001 | 0x0000)
#define color2 (WORD)(0x0002 | 0x0000)
#define color3 (WORD)(0x0003 | 0x0000)
#define color4 (WORD)(0x0004 | 0x0000)
#define color5 (WORD)(0x0005 | 0x0000)
#define color6 (WORD)(0x0006 | 0x0000)
#define color7 (WORD)(0x0007 | 0x0000)
#define color8 (WORD)(0x0008 | 0x0000)
#define color9 (WORD)(0x0008 | 0x0000)
#define COLOR(h, c) SetConsoleTextAttribute(h, c);
bool Head = false;
bool Neck = false;
bool fovchanger = false;
bool Chest = true;
bool UnlimitedAmmoDMR = false;
bool HeadESP = false;
bool Pelvis = false;
float CarValue = false;
bool smallplayer;
bool autokill = false;
bool NoBloom = false;
bool fastshot = false;
bool Toes = false;
float closerangedist = 20;
float SpeedValue = 5.1;
bool distanceesp = true;
bool testexploit = false;
static int increased_value;
bool fovcircle = true;
bool targetlines = true;
bool ShowMenu = true;
bool Esp = true;
bool Esp_box = false;
bool Esp_fbox = false;
bool while_rotating = false;
bool cornerbox = true;
bool Esp_line = false;
bool Aimbot = true;
bool Skeleton = true;
bool square_fov = false;
bool weaponesp = true;
bool ammoESP = false;
bool spinbot = false;
bool killall = false;
bool fillbox = false;
bool crosshair = false;
bool Esp_Skeleton = false;
bool lineheadesp = false;
bool Teleport = false;
bool cornerline = false;
float BoxWidthValue = 0.550;
float FontSize = 15;
float color_red = 1.;
float color_green = 0;
float color_blue = 0;
float ChangerFov = 2.5;

using namespace KeyAuth;

std::string name = "Ubutnubruh"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "1s48xB6D5j"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "47107e5ae9914e2835ddc28c72d57ad4172ad50bd3411c865febf1b1712337ec"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/"; // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);


/*
	Video on what ownerid and secret are https://youtu.be/uJ0Umy_C6Fg

	Video on how to add KeyAuth to your own application https://youtu.be/GB4XW_TsHqA

	Video to use Web Loader (control loader from customer panel) https://youtu.be/9-qgmsUUCK4
*/



struct playernameinf {

	uint64_t pNameStructure;
	uint64_t pNameEncryptedBuffer;
	int pNameLength;

};
float ChangerFOV = 80;

ImFont* m_pFont;
float smooth = 5;
static int VisDist = 2400;
float AimFOV = 150;
static int aimkeypos = 1;
static int hitboxpos = 0;
static int hitbox;
static int aimkey;





DWORD_PTR Uworld;
DWORD_PTR LocalPawn;
DWORD_PTR PlayerState;
DWORD_PTR Localplayer;
DWORD_PTR Rootcomp;
DWORD_PTR CurrentVehicle;
DWORD_PTR PlayerController;
DWORD_PTR Persistentlevel;
uintptr_t PlayerCameraManager;
Vector3 localactorpos;

uint64_t TargetPawn;
int localplayerID;

RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;
DWORD ScreenCenterX;
DWORD ScreenCenterY;
Vector3 LocalRelativeLocation; struct FBoxSphereBounds
{
	struct Vector3                                     Origin;                                                   // 0x0000(0x0018) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	struct Vector3                                     BoxExtent;                                                // 0x0018(0x0018) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	double                                             SphereRadius;                                             // 0x0030(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
};
static void xCreateWindow();
static void xInitD3d();
static void xMainLoop();
static void xShutdown();
static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;

typedef struct {
	float X, Y, Z;
} FVector;

typedef struct {
	float X, Y;
} FVector2D;

typedef struct {
	float Pitch;
	float Yaw;
	float Roll;
} FRotator;

typedef struct {
	FVector Location;
	FRotator Rotation;
	float FOV;
	float OrthoWidth;
	float OrthoNearClipPlane;
	float OrthoFarClipPlane;
	float AspectRatio;
} FMinimalViewInfo;

typedef struct {
	float M[4][4];
} FMatrix;

typedef struct {
	FVector ViewOrigin;
	char _padding_0[4];
	FMatrix ViewRotationMatrix;
	FMatrix ProjectionMatrix;
} FSceneViewProjectionData;




class UClass {
public:
	BYTE _padding_0[0x40];
	UClass* SuperClass;
};

class UObject {
public:
	PVOID VTableObject;
	DWORD ObjectFlags;
	DWORD InternalIndex;
	UClass* Class;
	BYTE _padding_0[0x8];
	UObject* Outer;

	inline BOOLEAN IsA(PVOID parentClass) {
		for (auto super = this->Class; super; super = super->SuperClass) {
			if (super == parentClass) {
				return TRUE;
			}
		}

		return FALSE;
	}
};

class FUObjectItem {
public:
	UObject* Object;
	DWORD Flags;
	DWORD ClusterIndex;
	DWORD SerialNumber;
	DWORD SerialNumber2;
};

class TUObjectArray {
public:
	FUObjectItem* Objects[9];
};

class GObjects {
public:
	TUObjectArray* ObjectArray;
	BYTE _padding_0[0xC];
	DWORD ObjectCount;
};


template<class T>
struct TArray {
	friend struct FString;

public:
	inline TArray() {
		Data = nullptr;
		Count = Max = 0;
	};

	inline INT Num() const {
		return Count;
	};

	inline T& operator[](INT i) {
		return Data[i];
	};

	inline BOOLEAN IsValidIndex(INT i) {
		return i < Num();
	}

private:
	T* Data;
	INT Count;
	INT Max;
};

struct FString : private TArray<WCHAR> {
	FString() {
		Data = nullptr;
		Max = Count = 0;
	}

	FString(LPCWSTR other) {
		Max = Count = static_cast<INT>(wcslen(other));

		if (Count) {
			Data = const_cast<PWCHAR>(other);
		}
	};

	inline BOOLEAN IsValid() {
		return Data != nullptr;
	}

	inline PWCHAR c_str() {
		return Data;
	}
};

VOID(*FreeInternal)(PVOID) = nullptr;

VOID Free(PVOID buffer) {
	FreeInternal(buffer);
}


#pragma once

namespace detail
{
	extern "C" void* _spoofer_stub();

	template <typename Ret, typename... Args>
	static inline auto shellcode_stub_helper(
		const void* shell,
		Args... args
	) -> Ret
	{
		auto fn = (Ret(*)(Args...))(shell);
		return fn(args...);
	}

	template <std::size_t Argc, typename>
	struct argument_remapper
	{
		template<
			typename Ret,
			typename First,
			typename Second,
			typename Third,
			typename Fourth,
			typename... Pack
		>
		static auto do_call(const void* shell, void* shell_param, First first, Second second,
			Third third, Fourth fourth, Pack... pack) -> Ret
		{
			return shellcode_stub_helper< Ret, First, Second, Third, Fourth, void*, void*, Pack... >(shell, first, second, third, fourth, shell_param, nullptr, pack...);
		}
	};

	template <std::size_t Argc>
	struct argument_remapper<Argc, std::enable_if_t<Argc <= 4>>
	{
		template<
			typename Ret,
			typename First = void*,
			typename Second = void*,
			typename Third = void*,
			typename Fourth = void*
		>
		static auto do_call(
			const void* shell,
			void* shell_param,
			First first = First{},
			Second second = Second{},
			Third third = Third{},
			Fourth fourth = Fourth{}
		) -> Ret
		{
			return shellcode_stub_helper<
				Ret,
				First,
				Second,
				Third,
				Fourth,
				void*,
				void*
			>(
				shell,
				first,
				second,
				third,
				fourth,
				shell_param,
				nullptr
			);
		}
	};
}

template <typename Ret, typename... Args>
static inline auto SpoofCall(Ret(*fn)(Args...), Args... args) -> Ret
{
	static const void* jmprbx = nullptr;
	if (!jmprbx) {
		const auto ntdll = reinterpret_cast<const unsigned char*>(::GetModuleHandleW(NULL));
		const auto dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(ntdll);
		const auto nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(ntdll + dos->e_lfanew);
		const auto sections = IMAGE_FIRST_SECTION(nt);
		const auto num_sections = nt->FileHeader.NumberOfSections;

		constexpr char section_name[5]{ '.', 't', 'e', 'x', 't' };
		const auto     section = std::find_if(sections, sections + num_sections, [&](const auto& s) {
			return std::equal(s.Name, s.Name + 5, section_name);
			});

		constexpr unsigned char instr_bytes[2]{ 0xFF, 0x26 };
		const auto              va = ntdll + section->VirtualAddress;
		jmprbx = std::search(va, va + section->Misc.VirtualSize, instr_bytes, instr_bytes + 2);
	}

	struct shell_params
	{
		const void* trampoline;
		void* function;
		void* rdx;
	};

	shell_params p
	{
		jmprbx,
		reinterpret_cast<void*>(fn)
	};

	using mapper = detail::argument_remapper<sizeof...(Args), void>;
	return mapper::template do_call<Ret, Args...>((const void*)&detail::_spoofer_stub, &p, args...);
}

namespace SpoofRuntime {
	inline float acosf_(float x)
	{
		return SpoofCall(acosf, x);
	}

	inline float atan2f_(float x, float y)
	{
		return SpoofCall(atan2f, x, y);
	}
}


#define BONE_HEAD_ID (68)
#define BONE_NECK_ID (67)
#define BONE_CHEST_ID (36)
#define BONE_PELVIS_ID (2)

FTransform GetBoneIndex(DWORD_PTR mesh, int index)
{

	bonearray = KmDrv->Rpm<DWORD_PTR>(mesh + 0x5f0);
	if (bonearray == NULL)
	{
		bonearray = KmDrv->Rpm<DWORD_PTR>(mesh + 0x5f0 + 0x10);
	}
	return KmDrv->Rpm<FTransform>(bonearray + (index * 0x60));
}
Vector3 GetBoneWithRotation(ULONG64 mesh, int index) {
	FTransform bone = GetBoneIndex(mesh, index);
	FTransform ComponentToWorld = KmDrv->Rpm<FTransform>(mesh + 0x240);
	D3DMATRIX Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}


D3DXMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0))
{
	float radPitch = (rot.x * float(M_PI) / 180.f);
	float radYaw = (rot.y * float(M_PI) / 180.f);
	float radRoll = (rot.z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}




double __fastcall Atan2(double a1, double a2)
{
	double result; // xmm0_8

	result = 0.0;
	if (a2 != 0.0 || a1 != 0.0)
		return atan2(a1, a2);
	return result;
}
double __fastcall FMod(double a1, double a2)
{
	if (fabs(a2) > 0.00000001)
		return fmod(a1, a2);
	else
		return 0.0;
}

double ClampAxis(double Angle)
{
	// returns Angle in the range (-360,360)
	Angle = FMod(Angle, (double)360.0);

	if (Angle < (double)0.0)
	{
		// shift to [0,360) range
		Angle += (double)360.0;
	}

	return Angle;
}

double NormalizeAxis(double Angle)
{
	// returns Angle in the range [0,360)
	Angle = ClampAxis(Angle);

	if (Angle > (double)180.0)
	{
		// shift to (-180,180]
		Angle -= (double)360.0;
	}

	return Angle;
}




FRotator Rotator(FQuat* F)
{
	const double SingularityTest = F->z * F->x - F->w * F->y;
	const double YawY = 2.f * (F->w * F->z + F->x * F->y);
	const double YawX = (1.f - 2.f * ((F->y * F->y) + (F->z * F->z)));

	const double SINGULARITY_THRESHOLD = 0.4999995f;
	const double RAD_TO_DEG = 57.295776;
	float Pitch, Yaw, Roll;

	if (SingularityTest < -SINGULARITY_THRESHOLD)
	{
		Pitch = -90.f;
		Yaw = (Atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = NormalizeAxis(-Yaw - (2.f * Atan2(F->x, F->w) * RAD_TO_DEG));
	}
	else if (SingularityTest > SINGULARITY_THRESHOLD)
	{
		Pitch = 90.f;
		Yaw = (Atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = NormalizeAxis(Yaw - (2.f * Atan2(F->x, F->w) * RAD_TO_DEG));
	}
	else
	{
		Pitch = (asin(2.f * SingularityTest) * RAD_TO_DEG);
		Yaw = (Atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = (Atan2(-2.f * (F->w * F->x + F->y * F->z), (1.f - 2.f * ((F->x * F->x) + (F->y * F->y)))) * RAD_TO_DEG);
	}

	FRotator RotatorFromQuat = FRotator{ Pitch, Yaw, Roll };
	return RotatorFromQuat;
}

struct CamewaDescwipsion
{
	float FieldOfView;
	Vector3 Rotation;
	Vector3 Location;
};
CamewaDescwipsion UndetectedCamera()
{
	CamewaDescwipsion VirtualCamera;
	__int64 ViewStates;
	__int64 ViewState;

	ViewStates = KmDrv->Rpm<__int64>(Localplayer + 0xD0);
	ViewState = KmDrv->Rpm<__int64>(ViewStates + 8);

	VirtualCamera.FieldOfView = KmDrv->Rpm<float>(PlayerController + 0x38C) * 90.f;

	VirtualCamera.Rotation.x = KmDrv->Rpm<double>(ViewState + 0x9C0);
	__int64 ViewportClient = KmDrv->Rpm<__int64>(Localplayer + 0x78);
	if (!ViewportClient) return VirtualCamera;
	__int64 AudioDevice = KmDrv->Rpm<__int64>(ViewportClient + 0x98);
	if (!AudioDevice) return VirtualCamera;
	__int64 FListener = KmDrv->Rpm<__int64>(AudioDevice + 0x1E0);
	if (!FListener) return VirtualCamera;
	FQuat Listener = KmDrv->Rpm<FQuat>(FListener);
	VirtualCamera.Rotation.y = Rotator(&Listener).Yaw;

	VirtualCamera.Location = KmDrv->Rpm<Vector3>(KmDrv->Rpm<uintptr_t>(Uworld + 0x110));
	return VirtualCamera;
}

float fov;


Vector3 ProjectWorldToScreen(Vector3 WorldLocation)
{
	CamewaDescwipsion vCamera = UndetectedCamera();
	vCamera.Rotation.x = (asin(vCamera.Rotation.x)) * (180.0 / M_PI);
	fov = vCamera.FieldOfView;

	D3DMATRIX tempMatrix = Matrix(vCamera.Rotation);

	Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	Vector3 vDelta = WorldLocation - vCamera.Location;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	return Vector3((Width / 2.0f) + vTransformed.x * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (Height / 2.0f) - vTransformed.y * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);
}

void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
}



void DrawStrokeText(int x, int y, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);

	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 255, 255)), utf_8_2.c_str());
}


void DrawSkeleton(DWORD_PTR mesh)
{
	Vector3 vHeadBoneOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 106));
	Vector3 vNeckOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 67));
	Vector3 vHipOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 2));

	Vector3 vUpperArmRightOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 101));
	Vector3 vElboRightOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 102));
	Vector3 vRightHandWristOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, /*58*/113));

	Vector3 vRightHipOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 78));
	Vector3 vRightKneeOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 79));
	Vector3 vRightAnkleOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 87));
	Vector3 vRightFootOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 83));


	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 35));
	Vector3 vElboLeftOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 10));
	Vector3 vLeftHandWristOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, /*30*/114/*39*/));

	Vector3 vLeftHipOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 71));
	Vector3 vLeftKneeOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 72));
	Vector3 vLeftAnkleOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 86));
	Vector3 vLeftFootOut = ProjectWorldToScreen(GetBoneWithRotation(mesh, 76));

	DrawLine(vHeadBoneOut.x, vHeadBoneOut.y, vNeckOut.x, vNeckOut.y, &Col.red, 0.7f);
	DrawLine(vNeckOut.x, vNeckOut.y, vHipOut.x, vHipOut.y, &Col.red, 0.7f);

	DrawLine(vNeckOut.x, vNeckOut.y, vUpperArmRightOut.x, vUpperArmRightOut.y, &Col.red, 0.7f);
	DrawLine(vUpperArmRightOut.x, vUpperArmRightOut.y, vElboRightOut.x, vElboRightOut.y, &Col.red, 0.7f);
	DrawLine(vElboRightOut.x, vElboRightOut.y, vRightHandWristOut.x, vRightHandWristOut.y, &Col.red, 0.7f);

	DrawLine(vHipOut.x, vHipOut.y, vRightHipOut.x, vRightHipOut.y, &Col.red, 0.7f);
	DrawLine(vRightHipOut.x, vRightHipOut.y, vRightKneeOut.x, vRightKneeOut.y, &Col.red, 0.7f);
	DrawLine(vRightKneeOut.x, vRightKneeOut.y, vRightAnkleOut.x, vRightAnkleOut.y, &Col.red, 0.7f);
	DrawLine(vRightAnkleOut.x, vRightAnkleOut.y, vRightFootOut.x, vRightFootOut.y, &Col.red, 0.7f);


	DrawLine(vNeckOut.x, vNeckOut.y, vUpperArmLeftOut.x, vUpperArmLeftOut.y, &Col.red, 0.7f);
	DrawLine(vUpperArmLeftOut.x, vUpperArmLeftOut.y, vElboLeftOut.x, vElboLeftOut.y, &Col.red, 0.7f);
	DrawLine(vElboLeftOut.x, vElboLeftOut.y, vLeftHandWristOut.x, vLeftHandWristOut.y, &Col.red, 0.7f);

	DrawLine(vHipOut.x, vHipOut.y, vLeftHipOut.x, vLeftHipOut.y, &Col.red, 0.7f);
	DrawLine(vLeftHipOut.x, vLeftHipOut.y, vLeftKneeOut.x, vLeftKneeOut.y, &Col.red, 0.7f);
	DrawLine(vLeftKneeOut.x, vLeftKneeOut.y, vLeftAnkleOut.x, vLeftAnkleOut.y, &Col.red, 0.7f);
	DrawLine(vLeftAnkleOut.x, vLeftAnkleOut.y, vLeftFootOut.x, vLeftFootOut.y, &Col.red, 0.7f);
}


float DrawOutlinedText(ImFont* pFont, const std::string& text, const ImVec2& pos, float size, ImU32 color, bool center)
{
	std::stringstream stream(text);
	std::string line;

	float y = 0.0f;
	int i = 0;

	while (std::getline(stream, line))
	{
		ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());

		if (center)
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}
		else
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}

		y = pos.y + textSize.y * (i + 1);
		i++;
	}
	return y;
}

void DrawText1(int x, int y, const char* str, RGBA* color)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}

void DrawCircle(int x, int y, int radius, RGBA* color, int segments)
{
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments);
}
void DrawBox(float X, float Y, float W, float H, const ImU32& color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(X + 1, Y + 1), ImVec2(((X + W) - 1), ((Y + H) - 1)), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}
void DrawFilledRect(int x, int y, int w, int h, ImU32 color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
}
void DrawNormalBox(int x, int y, int w, int h, int borderPx, ImU32 color)
{

	DrawFilledRect(x + borderPx, y, w, borderPx, color); //top 
	DrawFilledRect(x + w - w + borderPx, y, w, borderPx, color); //top 
	DrawFilledRect(x, y, borderPx, h, color); //left 
	DrawFilledRect(x, y + h - h + borderPx * 2, borderPx, h, color); //left 
	DrawFilledRect(x + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawFilledRect(x + w - w + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawFilledRect(x + w + borderPx, y, borderPx, h, color);//right 
	DrawFilledRect(x + w + borderPx, y + h - h + borderPx * 2, borderPx, h, color);//right 
}
void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness) {
	float lineW = (W / 3);
	float lineH = (H / 3);

	//black outlines
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

	//corners
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}

void Loading()
{
	printf("\n");
	printf(" Loading.");
	Sleep(600);
	system("cls");
	printf("\n");
	printf(" Loading..");
	Sleep(600);
	system("cls");
	printf("\n");
	printf(" Loading...");
	Sleep(600);
	system("cls");
}


std::wstring MBytesToWString(const char* lpcszString)
{
	int len = strlen(lpcszString);
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
	wchar_t* pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
	std::wstring wString = (wchar_t*)pUnicode;
	delete[] pUnicode;
	return wString;
}
std::string WStringToUTF8(const wchar_t* lpwcszWString)
{
	char* pElementText;
	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
	std::string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}

void DrawString(float fontSize, int x, int y, RGBA* color, bool bCenter, bool stroke, const char* pText, ...)
{
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 4;
		y = y - textSize.y;
	}
	if (stroke)
	{
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
	}
	ImGui::GetOverlayDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 153.0, color->B / 51.0, color->A / 255.0)), text.c_str());
}



typedef struct _FNlEntity
{
	uint64_t Actor;
	int ID;
	uint64_t mesh;
}FNlEntity;

std::vector<FNlEntity> entityList;


struct HandleDisposer
{
	using pointer = HANDLE;
	void operator()(HANDLE handle) const
	{
		if (handle != NULL || handle != INVALID_HANDLE_VALUE)
		{
			CloseHandle(handle);
		}
	}
};
using unique_handle = std::unique_ptr<HANDLE, HandleDisposer>;


static std::uint32_t _GetProcessId(std::string process_name) {
	PROCESSENTRY32 processentry;
	const unique_handle snapshot_handle(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

	if (snapshot_handle.get() == INVALID_HANDLE_VALUE)
		return 0;

	processentry.dwSize = sizeof(MODULEENTRY32);

	while (Process32Next(snapshot_handle.get(), &processentry) == TRUE) {
		if (process_name.compare(processentry.szExeFile) == 0)
			return processentry.th32ProcessID;
	}
	return 0;
}
// random standard header




DWORD Menuthread(LPVOID in)
{
	while (1)
	{
		if (MouseController::GetAsyncKeyState(VK_F1) & 1) {
			ShowMenu = !ShowMenu;
		}
		Sleep(2);
		if (MouseController::GetAsyncKeyState(VK_INSERT) & 1) {
			ShowMenu = !ShowMenu;
		}
		Sleep(2);
	}
}
#include <sstream>

template <typename T>
void readValue(const nlohmann::json& src, T& dest)
{
	if (!src.is_null())
	{
		if (src.is_string())
		{
			std::string value_str = src.get<std::string>();
			if (value_str.substr(0, 2) == "0x") // hex prefix
			{
				dest = static_cast<T>(std::stoul(value_str.substr(2), nullptr, 16));
			}
			else
			{
				dest = static_cast<T>(std::stoul(value_str, nullptr, 10));
			}
		}
		else
		{
			dest = src.get<T>();
		}
	}
}


void autoupdate()
{
	std::ifstream input_file{ "C:\\Windows\\offsets.json" };
	if (!input_file.good())
		throw std::invalid_argument("Invalid offsets.json file");

	nlohmann::json json;
	input_file >> json;

	readValue(json["offsets"]["uworld"], OFFSET_UWORLD);
	readValue(json["offsets"]["Gameinstance"], OFFSETS::Gameinstance);
	readValue(json["offsets"]["LocalPlayers"], OFFSETS::LocalPlayers);
	readValue(json["offsets"]["PlayerController"], OFFSETS::PlayerController);
	readValue(json["offsets"]["LocalPawn"], OFFSETS::LocalPawn);
	readValue(json["offsets"]["PlayerState"], OFFSETS::PlayerState);
	readValue(json["offsets"]["RootComponet"], OFFSETS::RootComponet);
	readValue(json["offsets"]["GameState"], OFFSETS::GameState);
	readValue(json["offsets"]["PersistentLevel"], OFFSETS::PersistentLevel);
	readValue(json["offsets"]["ActorCount"], OFFSETS::ActorCount);
	readValue(json["offsets"]["Cameramanager"], OFFSETS::Cameramanager);
	readValue(json["offsets"]["AActor"], OFFSETS::AActor);
	readValue(json["offsets"]["CurrentActor"], OFFSETS::CurrentActor);
	readValue(json["offsets"]["Mesh"], OFFSETS::Mesh);
	readValue(json["offsets"]["Revivefromdbnotime"], OFFSETS::Revivefromdbnotime);
	readValue(json["offsets"]["TeamId"], OFFSETS::TeamId);
	readValue(json["offsets"]["ActorTeamId"], OFFSETS::ActorTeamId);
	readValue(json["offsets"]["IsDBNO"], OFFSETS::IsDBNO);
	readValue(json["offsets"]["LocalActorPos"], OFFSETS::LocalActorPos);
	readValue(json["offsets"]["ComponetToWorld"], OFFSETS::ComponetToWorld);
	readValue(json["offsets"]["BoneArray"], OFFSETS::BoneArray);
	readValue(json["offsets"]["Velocity"], OFFSETS::Velocity);
	readValue(json["offsets"]["PawnPrivate"], OFFSETS::PawnPrivate);
	readValue(json["offsets"]["PlayerArray"], OFFSETS::PlayerArray);
	readValue(json["offsets"]["relativelocation"], OFFSETS::relativelocation);
	readValue(json["offsets"]["UCharacterMovementComponent"], OFFSETS::UCharacterMovementComponent);
	readValue(json["offsets"]["entity_actor"], OFFSETS::entity_actor);
	readValue(json["offsets"]["bIsReloadingWeapon"], OFFSETS::bIsReloadingWeapon);
	readValue(json["offsets"]["GlobalAnimRateScale"], OFFSETS::GlobalAnimRateScale);
	readValue(json["offsets"]["CurrentWeapon"], OFFSETS::CurrentWeapon);
}


struct slowly_printing_string {
	std::string data;
	long int delay;
};

std::ostream& operator<<(std::ostream& out, const slowly_printing_string& s) {
	for (const auto& c : s.data) {
		out << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
	}
	return out;
}

int main(int argc, const char* argv[])

{
	MouseController::Init();
	CreateThread(NULL, NULL, Menuthread, NULL, NULL, NULL);
	system("color 0c");
	system("curl --silent https://raw.githubusercontent.com/JeremyMiau/fortnite-offsets/main/offsets.json --output C:\\Windows\\offsets.json >nul 2>&1");
	autoupdate();
	system("color E");
	SetConsoleTitleA(skCrypt("Loader"));
	std::cout << slowly_printing_string{"\n Connecting...", 50 };
	system("cls");
	KeyAuthApp.init();
	if (!KeyAuthApp.data.success)
	{
		std::cout << slowly_printing_string{"\n Status: ", 50} << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	if (KeyAuthApp.checkblack()) {
		abort();
	}


	std::cout << slowly_printing_string{"\n BloudyWare", 10 };
	std::cout << slowly_printing_string{"\n Version 1.0", 10 };
	std::cout << slowly_printing_string{"\n Build 30/5/2023", 10 };
	std::cout << slowly_printing_string{"\n\n Welcome!", 10 };
	std::cout << slowly_printing_string{"\n\n [1] Login\n [2] Register\n\n\n Choose option: ", 50};
	int option;
	std::string username;
	std::string password;
	std::string key;

	std::cin >> option;
	switch (option)
	{
	case 1:
		std::cout << slowly_printing_string{"\n\n Enter username: ", 50};
		std::cin >> username;
		std::cout << slowly_printing_string{"\n Enter password: ", 50};
		std::cin >> password;
		KeyAuthApp.login(username, password);
		break;
	case 2:
		std::cout << slowly_printing_string{"\n\n Enter username: ", 50};
		std::cin >> username;
		std::cout << slowly_printing_string{"\n Enter password: ", 50};
		std::cin >> password;
		std::cout << slowly_printing_string{"\n Enter license: ", 50};
		std::cin >> key;
		KeyAuthApp.regstr(username, password, key);
		break;

	default:
		std::cout << slowly_printing_string{"\n\n Status: Failure: Invalid Selection", 50};
		Sleep(3000);
		exit(0);
	}

	if (!KeyAuthApp.data.success)
	{
		std::cout << slowly_printing_string{"\n Status: ", 50} << KeyAuthApp.data.message;

		Sleep(1500);
		exit(0);

	}
	SetConsoleTitleA("Fortnite BloudyWare External");
	system("cls");
menu_:
	int choice;
	system("color E");
	Loading();
	system("curl https://cdn.discordapp.com/attachments/1108040502965710870/1112748795478941756/Custom.sys -o C:\\Windows\\custom.sys --silent");
	system("curl https://cdn.discordapp.com/attachments/1108040502965710870/1112748795910967416/kdmapper.exe -o C:\\Windows\\maepp.exe --silent");
	Loading();
	Loading();
	system("cls");
	Sleep(2000);
	Beep(500, 500);
	system("cls");
	std::cout << slowly_printing_string{"\n Load Drivers? \n\n [1] Yes\n [2] No\n\n\n Choose option: ", 50};
	int choicu;
	std::cin >> choicu;
	switch (choicu)
	{
	case 1:
		std::cout << slowly_printing_string{"\n\n Loading Drivers ", 50};
		system("C:\\Windows\\custom.sys" "C:\\Windows\\maepp.exe");
		break;
	case 2:
		break;

	default:
		std::cout << slowly_printing_string{"\n\n Invalid Selection", 50};
		Sleep(3000);
		exit(0);
	}
	printf("\n [+] Press F2 In Game");
	while (true)
	{
		if (GetAsyncKeyState(VK_F2))
		{
			break;
			Beep(300, 300);
		}
	}
	while (hwnd == NULL)
	{

		XorS(wind, "Fortnite  ");
		hwnd = FindWindowA(0, wind.decrypt());
		Sleep(100);
	}
	processID = _GetProcessId("FortniteClient-Win64-Shipping.exe");
	KmDrv = new Memory(processID);
	base_address = KmDrv->GetModuleBase("FortniteClient-Win64-Shipping.exe");
	printf("\n [+] Loaded! Don't close this Window");
	xCreateWindow();
	xInitD3d();
	xMainLoop();
	xShutdown();
	return 0;
}



void SetWindowToTarget()
{
	while (true)
	{
		if (hwnd)
		{
			ZeroMemory(&GameRect, sizeof(GameRect));
			GetWindowRect(hwnd, &GameRect);
			Width = GameRect.right - GameRect.left;
			Height = GameRect.bottom - GameRect.top;
			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

			if (dwStyle & WS_BORDER)
			{
				GameRect.top += 32;
				Height -= 39;
			}
			ScreenCenterX = Width / 2;
			ScreenCenterY = Height / 2;
			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
		}
		else
		{
			exit(0);
		}
	}
}



const MARGINS Margin = { -1 };


void xCreateWindow()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.lpszClassName = "Windows18";
	wc.lpfnWndProc = WinProc;
	RegisterClassEx(&wc);

	if (hwnd)
	{
		GetClientRect(hwnd, &GameRect);
		POINT xy;
		ClientToScreen(hwnd, &xy);
		GameRect.left = xy.x;
		GameRect.top = xy.y;

		Width = GameRect.right;
		Height = GameRect.bottom;
	}
	else
		exit(2);

	Window = CreateWindowEx(NULL, "Windows18", "Windows189", WS_POPUP | WS_VISIBLE, 0, 0, Width, Height, 0, 0, 0, 0);

	DwmExtendFrameIntoClientArea(Window, &Margin);
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
	ShowWindow(Window, SW_SHOW);
	UpdateWindow(Window);
}
//Pasta Made by ! JeremyOnTop#0001

void xInitD3d()
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(3);

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = Width;
	d3dpp.BackBufferHeight = Height;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.hDeviceWindow = Window;
	d3dpp.Windowed = TRUE;

	p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui_ImplWin32_Init(Window);
	ImGui_ImplDX9_Init(D3dDevice);

	ImGuiStyle* style = &ImGui::GetStyle();

	ImVec4* colors = style->Colors;

	ImVec4 bgColor = ImColor(37, 37, 38);
	ImVec4 bgAAAColor = ImColor(24, 24, 24);
	ImVec4 lightBgColor = ImColor(82, 82, 85);
	ImVec4 veryLightBgColor = ImColor(90, 90, 95);

	ImVec4 panelColor = ImColor(51, 51, 55);
	ImVec4 panelHoverColor = ImColor(19, 110, 173);
	ImVec4 panelActiveColor = ImColor(250, 0, 10, 230);

	ImVec4 textColor = ImColor(255, 255, 255);
	ImVec4 textDisabledColor = ImColor(151, 151, 151);
	ImVec4 borderColor = ImColor(180, 180, 180, 255);
	ImVec4 black = ImColor(0, 0, 0);

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.1f, 0.1f, 0.1f, 0.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.1f, 0.1f, 0.0f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.1f, 0.1f, 0.1f, 0.0f));
	ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.118f, 0.118f, 0.118f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.118f, 0.118f, 0.118f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.118f, 0.118f, 0.118f, 1.0f));
	ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(ImColor(255, 0, 10)));
	ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(ImColor(255, 0, 10)));
	ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, ImVec4(ImColor(255, 0, 10)));


	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 8.0f;
	style->FrameRounding = 4.0f;
	style->FramePadding = ImVec2(5, 5);
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 0.0f;
	style->ScrollbarRounding = 1.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;
	style->Alpha = 1.f;

	p_Object->Release();
}

void aimbot(float x, float y)
{



	float ScreenCenterX = (Width / 2);
	float ScreenCenterY = (Height / 2);
	int AimSpeed = smooth;
	float TargetX = 0;
	float TargetY = 0;

	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}

	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	input.mi.dx = TargetX;
	input.mi.dy = TargetY;
	SPOOF_CALL(SendInput)(1, &input, sizeof(input));
	/*InjectedInputMouseInfo info = { 0 };
	info.DeltaX = TargetX;
	info.DeltaY = TargetY;
	InjectMouseInput(&info, 1);*/
	return;
}

void AimAt(DWORD_PTR entity)
{
	uint64_t currentactormesh = KmDrv->Rpm<uint64_t>(entity + 0x310);// ACharacter	Mesh	0x2f0	USkeletalMeshComponent*
	auto rootHead = GetBoneWithRotation(currentactormesh, 106);
	Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

	if (rootHeadOut.y != 0 || rootHeadOut.y != 0)
	{

		aimbot(rootHeadOut.x, rootHeadOut.y);
	}
}

bool IsVisible(uintptr_t mesh)
{




	float LastSumbitTime = KmDrv->Rpm<float>(mesh + 0x360);
	float LastRenderTimeOnScreen = KmDrv->Rpm<float>(mesh + 0x368);

	bool Visible = LastRenderTimeOnScreen + 0.06f >= LastSumbitTime;
	return Visible;
}



static auto DrawCircleFilled(int x, int y, int radius, RGBA* color) -> void
{
	ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}
namespace cumera
{
	Vector3 Location;
};
double GetCrossDistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
void OutlinedText(int x, int y, ImColor Color, const char* text)
{
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), Color, text);
}




void DrawESP() {





	if (square_fov) {
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(ScreenCenterX - AimFOV, ScreenCenterY - AimFOV), ImVec2(ScreenCenterX + AimFOV, ScreenCenterY + AimFOV), ImColor({ 255,0,10}), 1.5f);
		bool fovcircle = false;
		bool  fovcirclefilled = false;
	}
	if (fovcircle) {
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), AimFOV - ((fov - 80) * 2.5), ImColor(255,0,10), 100, 2.0f);
		bool square_fov = false;
		bool fovcircle = false;
		bool  fovcirclefilled = false;
	}







	if (hitboxpos == 0)
	{
		hitbox = 106; //head
	}
	else if (hitboxpos == 1)
	{
		hitbox = 67; //neck
	}
	else if (hitboxpos == 2)
	{
		hitbox = 36; //chest
	}
	else if (hitboxpos == 3)
	{
		hitbox = 2; //pelvis
	}

	if (aimkeypos == 0)
	{
		aimkey = 0x01;//left mouse button
	}
	else if (aimkeypos == 1)
	{
		aimkey = 0x02;//right mouse button
	}
	else if (aimkeypos == 2)
	{
		aimkey = 0x04;//middle mouse button
	}
	else if (aimkeypos == 3)
	{
		aimkey = 0x05;//x1 mouse button
	}
	else if (aimkeypos == 4)
	{
		aimkey = 0x06;//x2 mouse button
	}

	auto entityListCopy = entityList;
	float closestDistance = 280;
	DWORD_PTR closestPawn = NULL;
	Uworld = KmDrv->Rpm<DWORD_PTR>(base_address + OFFSET_UWORLD);
	DWORD_PTR Gameinstance = KmDrv->Rpm<DWORD_PTR>(Uworld + OFFSETS::Gameinstance);
	DWORD_PTR LocalPlayers = KmDrv->Rpm<DWORD_PTR>(Gameinstance + OFFSETS::LocalPlayers);
	Localplayer = KmDrv->Rpm<DWORD_PTR>(LocalPlayers);
	PlayerController = KmDrv->Rpm<DWORD_PTR>(Localplayer + OFFSETS::PlayerController);
	LocalPawn = KmDrv->Rpm<DWORD_PTR>(PlayerController + OFFSETS::LocalPawn);
	uintptr_t CurrentWeapon = KmDrv->Rpm<uintptr_t>(LocalPawn + 0x908);

	PlayerState = KmDrv->Rpm<DWORD_PTR>(LocalPawn + OFFSETS::PlayerState);
	Rootcomp = KmDrv->Rpm<DWORD_PTR>(LocalPawn + OFFSETS::RootComponet);
	Persistentlevel = KmDrv->Rpm<DWORD_PTR>(Uworld + OFFSETS::PersistentLevel);
	DWORD ActorCount = KmDrv->Rpm<DWORD>(Persistentlevel + OFFSETS::ActorCount);
	DWORD_PTR AActors = KmDrv->Rpm<DWORD_PTR>(Persistentlevel + OFFSETS::AActor);

	for (int i = 0; i < ActorCount; i++)
	{
		//uintptr_t CurrentWeapon = KmDrv->Rpm<uintptr_t>(LocalPawn + OFFSETS::CurrentWeapon); //CurrentWeapon Offset
		uint64_t CurrentActor = KmDrv->Rpm<uint64_t>(AActors + i * OFFSETS::CurrentActor);
		uint64_t CurrentActorMesh = KmDrv->Rpm<uint64_t>(CurrentActor + OFFSETS::Mesh);
		if (KmDrv->Rpm<float>(CurrentActor + OFFSETS::Revivefromdbnotime) != 10) continue;//changes by 10 every updated and it is importen/

		int MyTeamId = KmDrv->Rpm<int>(PlayerState + OFFSETS::TeamId);
		DWORD64 otherPlayerState = KmDrv->Rpm<uint64_t>(CurrentActor + OFFSETS::PlayerState);
		int ActorTeamId = KmDrv->Rpm<int>(otherPlayerState + OFFSETS::ActorTeamId);

		if (MyTeamId == ActorTeamId) continue;
		if (CurrentActor == LocalPawn) continue;

		Vector3 Headpos = GetBoneWithRotation(CurrentActorMesh, 106);
		localactorpos = KmDrv->Rpm<Vector3>(Rootcomp + OFFSETS::LocalActorPos);

		float distance = localactorpos.Distance(Headpos) / 100.f;

		//Pasted by Jeremy.#2603
		Vector3 bone0 = GetBoneWithRotation(CurrentActorMesh, 0);
		Vector3 bottom = ProjectWorldToScreen(bone0);
		Vector3 Headbox = ProjectWorldToScreen(Vector3(Headpos.x, Headpos.y, Headpos.z + 15));
		Vector3 w2shead = ProjectWorldToScreen(Headpos);
		float BoxHeight = (float)(Headbox.y - bottom.y);
		float BoxWidth = BoxHeight * 0.30;
		float LeftX = (float)Headbox.x - (BoxWidth / 1);
		float LeftY = (float)bottom.y;
		float CornerHeight = abs(Headbox.y - bottom.y);
		float CornerWidth = BoxHeight * 0.30;

		if (distance < VisDist)
		{
			if (Esp)
			{



				if (Esp_fbox)
				{
					ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(Headbox.x - (CornerWidth / 2), Headbox.y), ImVec2(bottom.x + (CornerWidth / 2), bottom.y), ImColor(0, 0, 0, 125), 0.75f);
				}


				if (HeadESP)
				{
					if (HeadESP)
					{
						Vector3 bottom1 = ProjectWorldToScreen(Vector3(Headpos.x + 10, Headpos.y - 10, Headpos.z));
						Vector3 bottom2 = ProjectWorldToScreen(Vector3(Headpos.x - 10, Headpos.y - 10, Headpos.z));

						Vector3 top1 = ProjectWorldToScreen(Vector3(Headpos.x + 10, Headpos.y - 10, Headpos.z + 17));
						Vector3 top2 = ProjectWorldToScreen(Vector3(Headpos.x - 10, Headpos.y - 10, Headpos.z + 17));

						ImU32 Cay = ImGui::GetColorU32({255, 255, 255, 255});

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(top1.x, top1.y), Cay, 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(top2.x, top2.y), Cay, 0.1f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom1.x, bottom1.y), ImVec2(bottom2.x, bottom2.y), Cay, 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(bottom2.x, bottom2.y), ImVec2(bottom2.x, bottom2.y), Cay, 0.1f);

						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top1.x, top1.y), ImVec2(top2.x, top2.y), Cay, 0.1f);
						ImGui::GetOverlayDrawList()->AddLine(ImVec2(top2.x, top2.y), ImVec2(top2.x, top2.y), Cay, 0.1f);

					}
				}



				if (Esp_box)
				{

					// rgba(0, 255, 231, 0)
					DrawBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, ImColor({ 255,0,10 }), 2.5f);


				}

				if (distanceesp)
				{
					char name[64];
					sprintf_s(name, skCrypt("%2.fm"), distance);
					DrawString(16, Headbox.x, Headbox.y - 15, &Col.red, true, true, name);
				}


				if (cornerbox)
				{

					// rgba(0, 255, 231, 0)
					DrawCorneredBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, ImColor({ 255,0,10 }), 2.5f);


				}







				if (Skeleton && distance < 2400)
				{
					DrawSkeleton(CurrentActorMesh);
				}

				if (Esp_line)
				{

					if (IsVisible) {
						DrawLine(Width / 2, Height, bottom.x, bottom.y, &Col.green, 1.5);
					}
					else
					{
						DrawLine(Width / 2, Height, bottom.x, bottom.y, &Col.white, 1.5);
					}

				}
			}
		}


		auto dx = w2shead.x - (Width / 2);
		auto dy = w2shead.y - (Height / 2);
		auto dist = sqrtf(dx * dx + dy * dy);

		if (IsVisible(CurrentActorMesh)) {

			if (dist < AimFOV && dist < closestDistance) {
				closestDistance = dist;
				closestPawn = CurrentActor;

			}
		}
	}

	if (Aimbot && closestPawn)
	{

		uint64_t CurrentActorMesh = KmDrv->Rpm<uint64_t>(closestPawn + 0x310);//  https://fn.dumps.host/search?query=Mesh  ACharacter	Mesh	0x2f0	USkeletalMeshComponent*
		if (CurrentActorMesh) {
			if (IsVisible(CurrentActorMesh)) {
				Vector3 Headpos2 = GetBoneWithRotation(CurrentActorMesh, 106);
				auto localactorpos1 = KmDrv->Rpm<Vector3>(Rootcomp + 0X128);
				float distance = localactorpos1.Distance(Headpos2) / 100.f;

				if (distance < VisDist && distance > 2) {
					if (Aimbot && closestPawn && SPOOF_CALL(GetAsyncKeyState)(aimkey) < 0) {



						AimAt(closestPawn);



					}
				}
			}


		}

	}



}


void render() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	if (ShowMenu) {

		static int tabs = 0;
		static int gk = false;

		ImGui::SetNextWindowSize({ 400,600.f });

		ImGui::Begin(("Urge Paid Public BETA"), 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoTitleBar);

		ImGui::Text("Urge Paid Public BETA");

		if (ImGui::Button("Aimbot"))
		{
			gk = 0;
		}

		ImGui::SameLine();

		if (ImGui::Button("Visuals"))
		{
			gk = 1;
		}

		ImGui::SameLine();


		if (ImGui::Button("Settings"))
		{
			gk = 2;
		}

		ImGui::SameLine();

		if (gk == 0)
		{
			{
				ImGui::Spacing();
				ImGui::Checkbox("Aimbot", &Aimbot);
				ImGui::Spacing();
				ImGui::Checkbox("Fov Circle", &fovcircle);
				ImGui::Spacing();
				ImGui::Combo(_xor_("AimKey").c_str(), &aimkeypos, aimkeys, sizeof(aimkeys) / sizeof(*aimkeys));
				ImGui::Spacing();
				ImGui::SliderFloat("Aim Fov", &AimFOV, 100, 300);
				ImGui::Spacing();
				ImGui::SliderFloat("Smooth", &smooth, 3, 20);
				ImGui::Spacing();
				HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);
				ImGui::Spacing();
			}
		}
		if (gk == 1)
		{
			{
				ImGui::Spacing();
				ImGui::Checkbox("Box Esp", &Esp_box);
				ImGui::Spacing();
				ImGui::Checkbox("Corner Box", &cornerbox);
				ImGui::Spacing();
				ImGui::Checkbox("Skeleton", &Skeleton);
				ImGui::Spacing();
				ImGui::Checkbox("Distance ESP", &distanceesp);
				ImGui::Spacing();
				ImGui::Checkbox("Head Esp", &HeadESP);
				ImGui::Spacing();
				ImGui::SliderInt("Esp Distance", &VisDist, 20, 200);
			}

		}

		if (gk == 2)
		{
			{
			}
		}



		ImGui::End();
	}

	DrawESP();

	ImGui::EndFrame();
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene();
	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}

//Pasta Made by ! JeremyOnTop#0001

MSG Message = { NULL };
int Loop = 0;
void xMainLoop()
{
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));

	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		if (GetAsyncKeyState(0x23) & 1)
			exit(8);

		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(hwnd, &rc);
		ClientToScreen(hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = NULL;
		io.ImeWindowHandle = hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			d3dpp.BackBufferWidth = Width;
			d3dpp.BackBufferHeight = Height;
			SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			D3dDevice->Reset(&d3dpp);
		}
		render();
		if (Loop == 0) {
			XorS(base, "Process base address: %p.\n");
			//Pasta Made by ! JeremyOnTop#0001
		}
		Loop = Loop + 1;
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	DestroyWindow(Window);
}


LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		xShutdown();
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			d3dpp.BackBufferWidth = LOWORD(lParam);
			d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = D3dDevice->Reset(&d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void xShutdown()
{
	TriBuf->Release();
	D3dDevice->Release();
	p_Object->Release();

	DestroyWindow(Window);
	UnregisterClass("Bluestacks", NULL);
}

