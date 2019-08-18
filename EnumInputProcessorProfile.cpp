#define VC_EXTRALEAN

#include <Windows.h>
#include <atlstr.h>
#include <atlbase.h>
#include <atlcom.h>
#include <msctf.h>
#include <imm.h>
#pragma comment(lib, "imm32.lib")

CString GuidToStr(const GUID& id) {
	WCHAR wc[100] = { 0 };
	ATLVERIFY(0 != StringFromGUID2(id, wc, 100));
	return wc;
}

CString ClsidToName(const CLSID& id) {
	CRegKey key;
	auto errorCode = key.Open(HKEY_CLASSES_ROOT, CString(L"CLSID\\") + GuidToStr(id), KEY_READ);
	if (NO_ERROR == errorCode) {
		WCHAR buffer[101] = { 0 };
		ULONG cch = 100;
		key.QueryStringValue(L"", buffer, &cch);
		return buffer;
	}
	return L"";
}

bool EnumIt() {
	CComPtr<ITfInputProcessorProfiles> profiles;
	{
		auto hr = profiles.CoCreateInstance(CLSID_TF_InputProcessorProfiles);
		if (hr != S_OK) {
			return false;
		}
	}
	CComQIPtr<ITfInputProcessorProfileMgr> profileMgr = static_cast<ITfInputProcessorProfiles*>(profiles);
	if (profileMgr == nullptr) {
		return false;
	}
	CComPtr<IEnumTfInputProcessorProfiles> enums;
	{
		auto hr = profileMgr->EnumProfiles(0, &enums);
		if (hr != S_OK) {
			return false;
		}
	}
	CString lines;
	lines.Append(L"          +------- D: TF_IPP_CAPS_DISABLEONTRANSITORY\r\n");
	lines.Append(L"          |+------ S: TF_IPP_CAPS_SECUREMODESUPPORT\r\n");
	lines.Append(L"          ||+----- U: TF_IPP_CAPS_UIELEMENTENABLED\r\n");
	lines.Append(L"          |||+---- L: TF_IPP_CAPS_COMLESSSUPPORT\r\n");
	lines.Append(L"          ||||+--- W: TF_IPP_CAPS_WOW16SUPPORT\r\n");
	lines.Append(L"          |||||+-- I: TF_IPP_CAPS_IMMERSIVESUPPORT\r\n");
	lines.Append(L"          ||||||+- T: TF_IPP_CAPS_SYSTRAYSUPPORT\r\n");
	lines.Append(L"          |||||||            \r\n");
	lines.Append(L"          |||||||            +--- A: TF_IPP_FLAG_ACTIVE\r\n");
	lines.Append(L"          |||||||            |+-- E: TF_IPP_FLAG_ENABLED\r\n");
	lines.Append(L"          |||||||            ||+- S: TF_IPP_FLAG_SUBSTITUTEDBYINPUTPROCESSOR\r\n");
	lines.Append(L"          |||||||            |||\r\n");
	while (true) {
		TF_INPUTPROCESSORPROFILE profile;
		{
			auto hr = enums->Next(1, &profile, nullptr);
			if (hr != S_OK) {
				break;
			}
		}

		lines.AppendFormat(L"%08lX <%C%C%C%C%C%C%C> %08lX <%C%C%C> %s CLSID %s \"%s\"\n"
			, (profile.dwCaps)
			, (profile.dwCaps & TF_IPP_CAPS_DISABLEONTRANSITORY) ? 'D' : '.'
			, (profile.dwCaps & TF_IPP_CAPS_SECUREMODESUPPORT) ? 'S' : '.'
			, (profile.dwCaps & TF_IPP_CAPS_UIELEMENTENABLED) ? 'U' : '.'
			, (profile.dwCaps & TF_IPP_CAPS_COMLESSSUPPORT) ? 'L' : '.'
			, (profile.dwCaps & TF_IPP_CAPS_WOW16SUPPORT) ? 'W' : '.'
			, (profile.dwCaps & TF_IPP_CAPS_IMMERSIVESUPPORT) ? 'I' : '.'
			, (profile.dwCaps & TF_IPP_CAPS_SYSTRAYSUPPORT) ? 'T' : '.'

			, (profile.dwFlags)
			, (profile.dwFlags & TF_IPP_FLAG_ACTIVE) ? 'A' : '.'
			, (profile.dwFlags & TF_IPP_FLAG_ENABLED) ? 'E' : '.'
			, (profile.dwFlags & TF_IPP_FLAG_SUBSTITUTEDBYINPUTPROCESSOR) ? 'S' : '.'

			, (profile.dwProfileType == TF_PROFILETYPE_INPUTPROCESSOR) ? L"TIP" : L"KBD"

			, static_cast<LPCWSTR>(GuidToStr(profile.clsid))
			, static_cast<LPCWSTR>(ClsidToName(profile.clsid))
		);
	}

	wprintf(L"%s", static_cast<LPCWSTR>(lines));

	return true;
}

int wmain()
{
	auto hr = CoInitialize(NULL);
	if (hr != S_OK) {
		return 1;
	}
	auto success = EnumIt();
	CoUninitialize();
	return success ? 0 : 1;
}
