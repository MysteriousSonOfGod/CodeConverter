#include "pch.h"
#include "VersionChecker.h"
#include "FTCore.h"

#ifdef __INDICATOR
const string msg = "Tiks!knekcbvos\"utgs!huoetjqnt\"tict!crf\"npv jopmgmfptff jp Gqrfz Ugsugr!5 bpd!gasnift wgrtkoou.!Rlfcsf. dqntkdft vrgscdjpg!vo!Hosgx!Vetves\"4!kf!{ov\"wbpt!vo!wsf\"tiks!knekcbvos0";
#else
const string msg = "Tiks!utsctfiy!wsfu gwndvipps!vhbv bte!pou\"inrlfoeovee\"io\"Fptey\"Tfutft 4\"aof fcrmkes\"vftsjqnt0 Qnebue-\"cppsjfes\"uqirbfioi uq Gqrfz Ugsugr!6 jh zqu!yaov uq vue!vhju tvrbveh{.";
#endif

bool MajorChecker::CheckMajor()
{
	return ftCheckVersion(ver_half_a_, ver_half_b_, major_);
}

bool MinorChecker::CheckMinor()
{
	return true; // Can check build version here if needed
}

VersionChecker::VersionChecker(int major, int minor)
{
	VersionCheckerParent::major_ = major;
	MinorCheckerParent::minor_ = minor;
}

void VersionChecker::Check()
{
	if(!(CheckMajor() && CheckMinor()))
	{
		string m = msg;
		for(int i = 0; i < m.size(); ++i)
		{
			m[i] -= i % 3;
		}

		const string cap = WindowExpertName() + mql4::string(".dll");

		MessageBoxA(NULL, m.c_str(), cap.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
		
		mql4::MathSrand(GetTickCount());
		int* naughty_pointer = (int*)(mql4::MathRand() % 65535);
		int nomral_int = *naughty_pointer + 42 + 34; // Oooops...
	}
}

void ftGetVersion(int& major, int& minor, int& rev, int& build)
{
	HRSRC res = FindResourceA(NULL, MAKEINTRESOURCEA(VS_VERSION_INFO), RT_VERSION);
	HGLOBAL hdata = LoadResource(NULL, res);
	LPVOID pres = LockResource(hdata);

	for(int i = 35; true; ++i)
	{
		if(*(((unsigned char*)pres)+i) == 254 && *(((unsigned char*)pres)+i-1) == 239 // Find siguature 0xFEEF04BD
			&& *(((unsigned char*)pres)+i-2) == 4 && *(((unsigned char*)pres)+i-3) == 189)
		{
			unsigned int ver_ms = *(unsigned int*)(((unsigned char*)pres)+i+5); // Most significant bits of file version
			unsigned int ver_ls = *(unsigned int*)(((unsigned char*)pres)+i+9); // Least significant bits of file version

			major = (ver_ms & 0xFFFF0000) >> 16;
			minor = (ver_ms & 0xFFFF);
			rev = (ver_ls & 0xFFFF0000) >> 16;
			build = (ver_ls & 0xFFFF);

			return;
		}
	}
}