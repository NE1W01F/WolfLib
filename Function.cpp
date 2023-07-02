#include "Function.h"

namespace Function {
    namespace call {
        Function::tCloseHandle closehandle = nullptr;
        Function::tCreateFileA createFileA = nullptr;
        Function::tVirtualAlloc virtualAlloc = nullptr;
        Function::tGetFileSize getFileSize = nullptr;
        Function::tReadFile readFile = nullptr;
        Function::tVirtualProtect virtualProtect = nullptr;
        Function::tGetFileAttributesA getFileAttributesA = nullptr;
        Function::tSearchPathA searchPathA = nullptr;
        Function::tFreeLibrary freeLibrary = nullptr;
        Function::tLoadLibraryA loadLibraryA = nullptr;
        Function::tSearchPathW searchPathW = nullptr;
        Function::tGetModuleFileNameW getModuleFileNameW = nullptr;
        Function::tSetConsoleTitleW setConsoleTitleW = nullptr;
        Function::tVirtualFree virtualFree = nullptr;
        Function::tGetEnvironmentVariableW getEnvironmentVariableW = nullptr;
        Function::tCreateFileW createFileW = nullptr;
        Function::tCreateFileMappingW createFileMappingW = nullptr;
        Function::tMapViewOfFile mapViewOfFile = nullptr;
        Function::tGetModuleHandleW getModuleHandleW = nullptr;
        Function::tSleep sleep = nullptr;
        Function::tCopyFileW copyFileW = nullptr;
        Function::tCreateDirectoryW createDirectoryW = nullptr;
        Function::tGetCurrentProcess getCurrentProcess = nullptr;
        Function::tGetProcAddress getProcAddress = nullptr;
        Function::tGetFileAttributesW getFileAttributesW = nullptr;
    }
}

bool Function::Init_Setup()
{

    // encrypted with https://www.stringencrypt.com (v1.4.0) [C/C++]
    // kernel32 = "C:\\Windows\\System32\\kernel32.dll"
    wchar_t kernel32[33] = { 0x27ED, 0x19ED, 0xE0AC, 0xC1AC, 0xAC6C, 0x8BEC, 0x6DAC, 0x4AAC,
                             0x28EC, 0x082C, 0xEEAB, 0xC0AB, 0x966B, 0x772B, 0x57AB, 0x4A2B,
                             0x286B, 0x062B, 0xE62A, 0xCCEA, 0xA8EA, 0x89AA, 0x552A, 0x366A,
                             0x286A, 0xF669, 0xE469, 0xC469, 0xA5A9, 0x7769, 0x55A9, 0x35E9,
                             0x3F29 };

    for (unsigned int bHckV = 0, PYWvm = 0; bHckV < 33; bHckV++)
    {
        PYWvm = kernel32[bHckV];
        PYWvm = ((PYWvm << 3) | ((PYWvm & 0xFFFF) >> 13)) & 0xFFFF;
        PYWvm += bHckV;
        PYWvm ^= 0xB969;
        PYWvm = (((PYWvm & 0xFFFF) >> 9) | (PYWvm << 7)) & 0xFFFF;
        PYWvm -= bHckV;
        kernel32[bHckV] = PYWvm;
    }

    void* moduleHandle = Function::pGetModuleHandle(kernel32);
    if (!moduleHandle)
        return false;


    unsigned char fcjkdnmdk[19] = { 0x17, 0x38, 0x4A, 0x1B, 0x39, 0x37, 0x3F, 0x02,
                                    0x30, 0x33, 0x34, 0x3E, 0x26, 0x34, 0x36, 0x26,
                                    0x3B, 0x16, 0xCE };

    for (unsigned int iITaM = 0, PMzyi = 0; iITaM < 19; iITaM++)
    {
        PMzyi = fcjkdnmdk[iITaM];
        PMzyi = ~PMzyi;
        PMzyi ^= 0x0E;
        PMzyi += 0xD8;
        PMzyi = ~PMzyi;
        PMzyi += iITaM;
        PMzyi -= 0xFA;
        fcjkdnmdk[iITaM] = PMzyi;
    }
    Function::call::getFileAttributesW = (Function::tGetFileAttributesW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(fcjkdnmdk));
    if (!Function::call::getFileAttributesW)
        return false;


    unsigned char dfcnmckxd[17] = { 0x7C, 0x5F, 0x42, 0x44, 0x28, 0xCB, 0x1F, 0x49,
                                0xF2, 0xD5, 0x19, 0xB3, 0x97, 0x75, 0xD6, 0x1C,
                                0x97 };

    for (unsigned int ShLlN = 0, mojbY = 0; ShLlN < 17; ShLlN++)
    {
        mojbY = dfcnmckxd[ShLlN];
        mojbY = ~mojbY;
        mojbY--;
        mojbY += ShLlN;
        mojbY++;
        mojbY ^= ShLlN;
        mojbY = (((mojbY & 0xFF) >> 7) | (mojbY << 1)) & 0xFF;
        mojbY -= 0x99;
        mojbY += ShLlN;
        mojbY = (((mojbY & 0xFF) >> 7) | (mojbY << 1)) & 0xFF;
        mojbY = ~mojbY;
        mojbY -= 0xDB;
        mojbY = ((mojbY << 1) | ((mojbY & 0xFF) >> 7)) & 0xFF;
        mojbY ^= 0xD2;
        mojbY++;
        dfcnmckxd[ShLlN] = mojbY;
    }
    Function::call::createDirectoryW = (Function::tCreateDirectoryW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(dfcnmckxd));
    if (!Function::call::createDirectoryW)
        return false;

    unsigned char vjmrkedefd[15] = { 0x3D, 0x97, 0xB3, 0x9A, 0xF2, 0x95, 0x76, 0x5E,
                                 0x76, 0xD6, 0x31, 0xD6, 0xB3, 0x93, 0x4D };

    for (unsigned int rvJXT = 0, fHEJg = 0; rvJXT < 15; rvJXT++)
    {
        fHEJg = vjmrkedefd[rvJXT];
        fHEJg = ((fHEJg << 7) | ((fHEJg & 0xFF) >> 1)) & 0xFF;
        fHEJg -= 0xBB;
        fHEJg = ((fHEJg << 2) | ((fHEJg & 0xFF) >> 6)) & 0xFF;
        fHEJg -= 0x33;
        fHEJg = ((fHEJg << 2) | ((fHEJg & 0xFF) >> 6)) & 0xFF;
        fHEJg ^= rvJXT;
        fHEJg = (((fHEJg & 0xFF) >> 1) | (fHEJg << 7)) & 0xFF;
        fHEJg = ~fHEJg;
        vjmrkedefd[rvJXT] = fHEJg;
    }
    Function::call::getProcAddress = (Function::tGetProcAddress)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(vjmrkedefd));
    if (!Function::call::getProcAddress)
        return false;

    unsigned char emcvksdms[18] = { 0xAE, 0x25, 0x60, 0xBB, 0x62, 0x7D, 0x7C, 0x1F,
                                    0x02, 0x69, 0xF8, 0x6F, 0x02, 0x31, 0x28, 0x6F,
                                    0x6E, 0xA2 };

    for (unsigned int KUEtR = 0, zuZWK = 0; KUEtR < 18; KUEtR++)
    {
        zuZWK = emcvksdms[KUEtR];
        zuZWK++;
        zuZWK ^= KUEtR;
        zuZWK = ~zuZWK;
        zuZWK ^= 0x4D;
        zuZWK = ((zuZWK << 6) | ((zuZWK & 0xFF) >> 2)) & 0xFF;
        emcvksdms[KUEtR] = zuZWK;
    }
    Function::call::getCurrentProcess = (Function::tGetCurrentProcess)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(emcvksdms));
    if (!Function::call::getCurrentProcess)
        return false;

    unsigned char bfdedgfds[10] = { 0xAA, 0x76, 0x5D, 0x44, 0x77, 0x30, 0x29, 0x20,
                                0x2E, 0x6C };

    for (unsigned int Kquoc = 0, uzMnY = 0; Kquoc < 10; Kquoc++)
    {
        uzMnY = bfdedgfds[Kquoc];
        uzMnY = ~uzMnY;
        uzMnY ^= Kquoc;
        uzMnY = (((uzMnY & 0xFF) >> 4) | (uzMnY << 4)) & 0xFF;
        uzMnY--;
        uzMnY -= Kquoc;
        uzMnY ^= 0xD7;
        uzMnY = ~uzMnY;
        uzMnY = ((uzMnY << 4) | ((uzMnY & 0xFF) >> 4)) & 0xFF;
        uzMnY += Kquoc;
        uzMnY ^= 0x84;
        bfdedgfds[Kquoc] = uzMnY;
    }
    Function::call::copyFileW = (Function::tCopyFileW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(bfdedgfds));
    if (!Function::call::copyFileW)
        return false;

    unsigned char ldskcvjksd[6] = { 0xB2, 0x0A, 0xE1, 0x9D, 0x2D, 0xAA };

    for (unsigned int PLvRI = 0, nvqpG = 0; PLvRI < 6; PLvRI++)
    {
        nvqpG = ldskcvjksd[PLvRI];
        nvqpG = ~nvqpG;
        nvqpG = ((nvqpG << 2) | ((nvqpG & 0xFF) >> 6)) & 0xFF;
        nvqpG -= PLvRI;
        nvqpG = (((nvqpG & 0xFF) >> 4) | (nvqpG << 4)) & 0xFF;
        nvqpG -= PLvRI;
        ldskcvjksd[PLvRI] = nvqpG;
    }
    Function::call::sleep = (Function::tSleep)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(ldskcvjksd));
    if (!Function::call::sleep)
        return false;

    unsigned char ndgheded[17] = { 0x61, 0x40, 0xB0, 0x56, 0xB5, 0xBD, 0xAD, 0xAB,
                               0xBF, 0x45, 0xBD, 0xAD, 0xA2, 0xAD, 0xA5, 0xB8,
                               0x1A };

    for (unsigned int Zdicb = 0, fYLdT = 0; Zdicb < 17; Zdicb++)
    {
        fYLdT = ndgheded[Zdicb];
        fYLdT ^= 0x3C;
        fYLdT ^= Zdicb;
        fYLdT = ~fYLdT;
        fYLdT--;
        fYLdT += Zdicb;
        fYLdT -= 0xD1;
        fYLdT = ~fYLdT;
        fYLdT -= Zdicb;
        fYLdT += 0x18;
        ndgheded[Zdicb] = fYLdT;
    }
    Function::call::getModuleHandleW = (Function::tGetModuleHandleW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(ndgheded));
    if (!Function::call::getModuleHandleW)
        return false;

    unsigned char gnbsjcvsd[19] = { 0xFF, 0x2F, 0x5E, 0x9A, 0xED, 0x1F, 0x7C, 0x83,
                                0xC6, 0x18, 0x60, 0x84, 0xEB, 0x14, 0x4D, 0x86,
                                0xDF, 0x08, 0x25 };

    for (unsigned int Yctid = 0, RSGqI = 0; Yctid < 19; Yctid++)
    {
        RSGqI = gnbsjcvsd[Yctid];
        RSGqI = (((RSGqI & 0xFF) >> 4) | (RSGqI << 4)) & 0xFF;
        RSGqI ^= 0xBE;
        RSGqI = ((RSGqI << 6) | ((RSGqI & 0xFF) >> 2)) & 0xFF;
        RSGqI -= Yctid;
        RSGqI += 0x5C;
        RSGqI += Yctid;
        RSGqI--;
        RSGqI += Yctid;
        RSGqI--;
        RSGqI = (((RSGqI & 0xFF) >> 2) | (RSGqI << 6)) & 0xFF;
        RSGqI ^= 0xE9;
        gnbsjcvsd[Yctid] = RSGqI;
    }
    Function::call::createFileMappingW = (Function::tCreateFileMappingW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(gnbsjcvsd));
    if (!Function::call::createFileMappingW)
        return false;

    unsigned char sdkvcnmdk[14] = { 0xD9, 0x50, 0x47, 0xD5, 0xC9, 0x50, 0xC7, 0x5C,
                                0x49, 0xD8, 0xCE, 0xCC, 0xCB, 0xF9 };

    for (unsigned int XaOYz = 0, ObCxG = 0; XaOYz < 14; XaOYz++)
    {
        ObCxG = sdkvcnmdk[XaOYz];
        ObCxG = ((ObCxG << 1) | ((ObCxG & 0xFF) >> 7)) & 0xFF;
        ObCxG--;
        ObCxG = ~ObCxG;
        ObCxG ^= XaOYz;
        sdkvcnmdk[XaOYz] = ObCxG;
    }
    Function::call::mapViewOfFile = (Function::tMapViewOfFile)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(sdkvcnmdk));
    if (!Function::call::mapViewOfFile)
        return false;

    unsigned char scsccvcvd[24] = { 0x86, 0x06, 0x5A, 0x96, 0x02, 0x6A, 0x0E, 0x6A,
                                0x66, 0x6A, 0x7E, 0x56, 0x42, 0x22, 0xB2, 0x66,
                                0xD2, 0xB6, 0x8E, 0x8A, 0x8A, 0xA6, 0x76, 0x21 };

    for (unsigned int XKyFs = 0, kIDCs = 0; XKyFs < 24; XKyFs++)
    {
        kIDCs = scsccvcvd[XKyFs];
        kIDCs--;
        kIDCs = (((kIDCs & 0xFF) >> 3) | (kIDCs << 5)) & 0xFF;
        kIDCs ^= XKyFs;
        kIDCs ^= 0x13;
        kIDCs = (((kIDCs & 0xFF) >> 7) | (kIDCs << 1)) & 0xFF;
        scsccvcvd[XKyFs] = kIDCs;
    }
    Function::call::getEnvironmentVariableW = (Function::tGetEnvironmentVariableW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(scsccvcvd));
    if (!Function::call::getEnvironmentVariableW)
        return false;

    unsigned char idjmvkds[12] = { 0xF5, 0x46, 0x47, 0x3E, 0x2D, 0x02, 0x3F, 0x38,
                               0x3F, 0x4E, 0x3B, 0x81 };

    for (unsigned int cezqo = 0, BvVUo = 0; cezqo < 12; cezqo++)
    {
        BvVUo = idjmvkds[cezqo];
        BvVUo ^= 0x01;
        BvVUo -= cezqo;
        BvVUo -= 0x09;
        BvVUo = (((BvVUo & 0xFF) >> 1) | (BvVUo << 7)) & 0xFF;
        BvVUo = ~BvVUo;
        BvVUo ^= cezqo;
        BvVUo ^= 0xBB;
        BvVUo += 0x92;
        BvVUo ^= cezqo;
        idjmvkds[cezqo] = BvVUo;
    }
    Function::call::closehandle = (Function::tCloseHandle)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(idjmvkds));
    if (!Function::call::closehandle)
        return false;

    unsigned char bdffdwsw[12] = { 0x3B, 0x88, 0xF9, 0x19, 0x49, 0x08, 0x98, 0x3A,
                               0xF9, 0x48, 0x48, 0xEE };

    for (unsigned int HjPcS = 0, DmwVy = 0; HjPcS < 12; HjPcS++)
    {
        DmwVy = bdffdwsw[HjPcS];
        DmwVy ^= 0x03;
        DmwVy += 0xAC;
        DmwVy = (((DmwVy & 0xFF) >> 2) | (DmwVy << 6)) & 0xFF;
        DmwVy ^= 0x9A;
        DmwVy--;
        DmwVy = ~DmwVy;
        DmwVy = (((DmwVy & 0xFF) >> 2) | (DmwVy << 6)) & 0xFF;
        DmwVy--;
        bdffdwsw[HjPcS] = DmwVy;
    }
    Function::call::virtualFree = (Function::tVirtualFree)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(bdffdwsw));
    if (!Function::call::virtualFree)
        return false;

    unsigned char jksdnvdsb[12] = { 0x6D, 0x7E, 0x0F, 0x4F, 0x1E, 0x0F, 0x3D, 0xCC,
                                0x9E, 0x0F, 0x4D, 0x59 };

    for (unsigned int HhxDG = 0, aovtN = 0; HhxDG < 12; HhxDG++)
    {
        aovtN = jksdnvdsb[HhxDG];
        aovtN = ((aovtN << 4) | ((aovtN & 0xFF) >> 4)) & 0xFF;
        aovtN ^= 0x92;
        aovtN = ~aovtN;
        aovtN -= 0x84;
        aovtN ^= 0x31;
        aovtN -= 0x04;
        aovtN ^= 0x41;
        jksdnvdsb[HhxDG] = aovtN;
    }
    Function::call::createFileA = (Function::tCreateFileA)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(jksdnvdsb));
    if (!Function::call::createFileA)
        return false;

    unsigned char vmfkerdk[12] = { 0x53, 0x21, 0x2B, 0x34, 0x1E, 0x2E, 0x4A, 0x28,
                               0x22, 0x2A, 0x39, 0x85 };

    for (unsigned int agOcl = 0, VtlzF = 0; agOcl < 12; agOcl++)
    {
        VtlzF = vmfkerdk[agOcl];
        VtlzF += agOcl;
        VtlzF ^= agOcl;
        VtlzF++;
        VtlzF ^= agOcl;
        VtlzF -= 0x98;
        VtlzF = ~VtlzF;
        vmfkerdk[agOcl] = VtlzF;
    }
    Function::call::createFileW = (Function::tCreateFileW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(vmfkerdk));
    if (!Function::call::createFileW)
        return false;

    unsigned char fjsdndfk[12] = { 0xFA, 0x0C, 0x93, 0x03, 0xAB, 0xD3, 0x0C, 0x5A,
                               0xAB, 0x23, 0x0C, 0xF0 };

    for (unsigned int qcgTy = 0, DQAIP = 0; qcgTy < 12; qcgTy++)
    {
        DQAIP = fjsdndfk[qcgTy];
        DQAIP++;
        DQAIP = (((DQAIP & 0xFF) >> 3) | (DQAIP << 5)) & 0xFF;
        DQAIP = ~DQAIP;
        DQAIP += 0xA3;
        DQAIP ^= 0x64;
        fjsdndfk[qcgTy] = DQAIP;
    }
    Function::call::getFileSize = (Function::tGetFileSize)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(fjsdndfk));
    if (!Function::call::getFileSize)
        return false;

    unsigned char tkdkvnds[9] = { 0xAC, 0x30, 0x38, 0xBB, 0xA6, 0x3A, 0xBD, 0x3C,
                              0x93 };

    for (unsigned int TbFWB = 0, KPRJw = 0; TbFWB < 9; TbFWB++)
    {
        KPRJw = tkdkvnds[TbFWB];
        KPRJw++;
        KPRJw -= TbFWB;
        KPRJw -= 0xD7;
        KPRJw -= TbFWB;
        KPRJw = (((KPRJw & 0xFF) >> 7) | (KPRJw << 1)) & 0xFF;
        KPRJw ^= 0x08;
        KPRJw -= 0x53;
        tkdkvnds[TbFWB] = KPRJw;
    }
    Function::call::readFile = (Function::tReadFile)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(tkdkvnds));
    if (!Function::call::readFile)
        return false;

    unsigned char xkdfksdk[13] = { 0x32, 0x86, 0x5F, 0x69, 0x3E, 0x44, 0x9A, 0x5E,
                               0x34, 0x45, 0x97, 0x95, 0x55 };

    for (unsigned int aXeds = 0, mlLnX = 0; aXeds < 13; aXeds++)
    {
        mlLnX = xkdfksdk[aXeds];
        mlLnX ^= aXeds;
        mlLnX += 0x9A;
        mlLnX = (((mlLnX & 0xFF) >> 3) | (mlLnX << 5)) & 0xFF;
        mlLnX ^= 0xC8;
        mlLnX -= aXeds;
        mlLnX += 0x1D;
        mlLnX -= aXeds;
        mlLnX = (((mlLnX & 0xFF) >> 3) | (mlLnX << 5)) & 0xFF;
        mlLnX -= 0x77;
        xkdfksdk[aXeds] = mlLnX;
    }
    Function::call::virtualAlloc = (Function::tVirtualAlloc)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(xkdfksdk));
    if (!Function::call::virtualAlloc)
        return false;

    unsigned char qkedkdike[15] = { 0xAD, 0xC0, 0xC9, 0xCB, 0xCC, 0xB8, 0xC3, 0xA7,
                                0xC9, 0xC6, 0xCB, 0xBC, 0xBA, 0xCB, 0x57 };

    for (unsigned int EGUcr = 0, MkLbW = 0; EGUcr < 15; EGUcr++)
    {
        MkLbW = qkedkdike[EGUcr];
        MkLbW += 0x8C;
        MkLbW -= EGUcr;
        MkLbW -= 0xE4;
        MkLbW += EGUcr;
        MkLbW++;
        qkedkdike[EGUcr] = MkLbW;
    }
    Function::call::virtualProtect = (Function::tVirtualProtect)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(qkedkdike));
    if (!Function::call::virtualProtect)
        return false;

    unsigned char zklrfkrkd[19] = { 0x96, 0xB4, 0xC3, 0x93, 0xB8, 0xB1, 0xAC, 0x90,
                                0xB3, 0xB1, 0xBD, 0xA8, 0xA9, 0xBC, 0xBB, 0xAC,
                                0xA2, 0x70, 0x2F };

    for (unsigned int AraQw = 0, AoORv = 0; AraQw < 19; AraQw++)
    {
        AoORv = zklrfkrkd[AraQw];
        AoORv--;
        AoORv -= AraQw;
        AoORv++;
        AoORv += AraQw;
        AoORv--;
        AoORv ^= AraQw;
        AoORv += AraQw;
        AoORv -= 0x4E;
        zklrfkrkd[AraQw] = AoORv;
    }
    Function::call::getFileAttributesA = (Function::tGetFileAttributesA)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(zklrfkrkd));
    if (!Function::call::getFileAttributesA)
        return false;

    unsigned char bhskfdks[12] = { 0xC7, 0x39, 0xAB, 0xF8, 0x04, 0x96, 0x08, 0xD7,
                               0xA4, 0x50, 0x1E, 0x37 };

    for (unsigned int NYmaI = 0, vSVQe = 0; NYmaI < 12; NYmaI++)
    {
        vSVQe = bhskfdks[NYmaI];
        vSVQe = (((vSVQe & 0xFF) >> 1) | (vSVQe << 7)) & 0xFF;
        vSVQe -= 0x36;
        vSVQe = (((vSVQe & 0xFF) >> 3) | (vSVQe << 5)) & 0xFF;
        vSVQe -= NYmaI;
        vSVQe ^= NYmaI;
        vSVQe = ~vSVQe;
        vSVQe++;
        vSVQe ^= 0xED;
        vSVQe ^= NYmaI;
        vSVQe = ((vSVQe << 4) | ((vSVQe & 0xFF) >> 4)) & 0xFF;
        vSVQe ^= NYmaI;
        vSVQe = (((vSVQe & 0xFF) >> 5) | (vSVQe << 3)) & 0xFF;
        bhskfdks[NYmaI] = vSVQe;
    }
    Function::call::searchPathA = (Function::tSearchPathA)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(bhskfdks));
    if (!Function::call::searchPathA)
        return false;

    unsigned char hdklfglds[13] = { 0x13, 0xCF, 0xA1, 0xBF, 0xD3, 0xEF, 0x51, 0x60,
                                0x31, 0x30, 0x90, 0xFD, 0x88 };

    for (unsigned int neqPB = 0, DBeri = 0; neqPB < 13; neqPB++)
    {
        DBeri = hdklfglds[neqPB];
        DBeri -= 0xC8;
        DBeri += neqPB;
        DBeri ^= neqPB;
        DBeri = ((DBeri << 4) | ((DBeri & 0xFF) >> 4)) & 0xFF;
        DBeri = ~DBeri;
        DBeri ^= neqPB;
        DBeri = ~DBeri;
        DBeri--;
        DBeri = ~DBeri;
        hdklfglds[neqPB] = DBeri;
    }
    Function::call::loadLibraryA = (Function::tLoadLibraryA)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(hdklfglds));
    if (!Function::call::loadLibraryA)
        return false;

    unsigned char wbdfghde[12] = { 0x53, 0xBE, 0x96, 0x90, 0x5F, 0xA4, 0x90, 0xB2,
                               0x92, 0xCE, 0xDE, 0xEE };

    for (unsigned int hzbAT = 0, mwzxi = 0; hzbAT < 12; hzbAT++)
    {
        mwzxi = wbdfghde[hzbAT];
        mwzxi = ~mwzxi;
        mwzxi--;
        mwzxi = ((mwzxi << 7) | ((mwzxi & 0xFF) >> 1)) & 0xFF;
        mwzxi ^= 0x39;
        mwzxi += 0x9A;
        mwzxi -= hzbAT;
        mwzxi ^= 0xC0;
        wbdfghde[hzbAT] = mwzxi;
    }
    Function::call::freeLibrary = (Function::tFreeLibrary)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(wbdfghde));
    if (!Function::call::freeLibrary)
        return false;

    unsigned char vskfdjksd[12] = { 0xE7, 0x58, 0x7A, 0xF4, 0x6E, 0x48, 0x0A, 0x84,
                                0xEE, 0x50, 0xDB, 0x93 };

    for (unsigned int iunEb = 0, rjLnV = 0; iunEb < 12; iunEb++)
    {
        rjLnV = vskfdjksd[iunEb];
        rjLnV = (((rjLnV & 0xFF) >> 1) | (rjLnV << 7)) & 0xFF;
        rjLnV = ~rjLnV;
        rjLnV += iunEb;
        rjLnV ^= 0x39;
        rjLnV = (((rjLnV & 0xFF) >> 2) | (rjLnV << 6)) & 0xFF;
        rjLnV ^= 0xE1;
        rjLnV--;
        rjLnV = ~rjLnV;
        rjLnV--;
        vskfdjksd[iunEb] = rjLnV;
    }
    Function::call::searchPathW = (Function::tSearchPathW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(vskfdjksd));
    if (!Function::call::searchPathW)
        return false;

    unsigned char klsdjfjsd[19] = { 0x0B, 0x03, 0x72, 0xAE, 0xA0, 0x44, 0xC6, 0xE9,
                                0x23, 0x21, 0x3D, 0xCD, 0x0F, 0xCC, 0x41, 0x3A,
                                0x4B, 0xE0, 0xBE };

    for (unsigned int InZCq = 0, hBHbZ = 0; InZCq < 19; InZCq++)
    {
        hBHbZ = klsdjfjsd[InZCq];
        hBHbZ ^= InZCq;
        hBHbZ++;
        hBHbZ += InZCq;
        hBHbZ++;
        hBHbZ += InZCq;
        hBHbZ -= 0x17;
        hBHbZ = ((hBHbZ << 5) | ((hBHbZ & 0xFF) >> 3)) & 0xFF;
        hBHbZ ^= 0x99;
        hBHbZ += InZCq;
        klsdjfjsd[InZCq] = hBHbZ;
    }
    Function::call::getModuleFileNameW = (Function::tGetModuleFileNameW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(klsdjfjsd));
    if (!Function::call::getModuleFileNameW)
        return false;

    unsigned char ckfgkedke[17] = { 0xB1, 0xB5, 0x6E, 0x03, 0xB4, 0x75, 0xAC, 0x3A,
                                0x7B, 0xB9, 0x7A, 0xB9, 0x73, 0xF9, 0x3C, 0x38,
                                0x5A };

    for (unsigned int COwzc = 0, VfRyI = 0; COwzc < 17; COwzc++)
    {
        VfRyI = ckfgkedke[COwzc];
        VfRyI ^= 0x9D;
        VfRyI--;
        VfRyI += COwzc;
        VfRyI = ((VfRyI << 2) | ((VfRyI & 0xFF) >> 6)) & 0xFF;
        VfRyI -= COwzc;
        VfRyI -= 0xC1;
        VfRyI -= COwzc;
        VfRyI -= 0x79;
        VfRyI = ~VfRyI;
        VfRyI ^= 0x6E;
        VfRyI -= 0x90;
        ckfgkedke[COwzc] = VfRyI;
    }
    Function::call::setConsoleTitleW = (Function::tSetConsoleTitleW)Function::pGetProcAddress(moduleHandle, reinterpret_cast<char*>(ckfgkedke));
    if (!Function::call::setConsoleTitleW)
        return false;


    return true;
}

void* Function::Memcpy(void* dst, const void* src, unsigned int cnt)
{
    char* pszDest = (char*)dst;
    const char* pszSource = (const char*)src;
    if ((pszDest != NULL) && (pszSource != NULL))
    {
        while (cnt)
        {
            *(pszDest++) = *(pszSource++);
            --cnt;
        }
    }

    return dst;
}

int Function::_strcmp(const char* str1, const char* str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            break;
        }
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

void Function::GetLowerLetters(WCHAR* input)
{
    wchar_t big_letters[27] = { 0x64BC, 0x64C6, 0x64A0, 0x64B8, 0x64BA, 0x64C2, 0x64B8, 0x649E,
                            0x64A8, 0x64A8, 0x6488, 0x64AA, 0x648A, 0x648C, 0x648C, 0x648C,
                            0x648E, 0x648E, 0x648E, 0x64A8, 0x64A2, 0x6476, 0x649A, 0x6470,
                            0x6486, 0x6482, 0x63E6 };

    for (unsigned int xkYlO = 0, elYMr = 0; xkYlO < 27; xkYlO++)
    {
        elYMr = big_letters[xkYlO];
        elYMr++;
        elYMr = (((elYMr & 0xFFFF) >> 1) | (elYMr << 15)) & 0xFFFF;
        elYMr += 0xA69B;
        elYMr += xkYlO;
        elYMr -= 0x58A8;
        big_letters[xkYlO] = elYMr;
    }
    wchar_t little_letters[27] = { 0x401C, 0x001E, 0xC019, 0x401D, 0x001E, 0x801F, 0xC01E, 0x001C,
                               0xC01D, 0x401E, 0xC01A, 0x801F, 0x001C, 0xC01C, 0x401D, 0xC01D,
                               0x801E, 0x001F, 0x801F, 0x4023, 0x0023, 0x001E, 0x0023, 0x401E,
                               0x8021, 0x8021, 0x8006 };

    for (unsigned int BesJb = 0, TWPXK = 0; BesJb < 27; BesJb++)
    {
        TWPXK = little_letters[BesJb];
        TWPXK = ~TWPXK;
        TWPXK = (((TWPXK & 0xFFFF) >> 14) | (TWPXK << 2)) & 0xFFFF;
        TWPXK = ~TWPXK;
        TWPXK -= BesJb;
        little_letters[BesJb] = TWPXK;
    }
    int size = _strlen(input);

    for (int i = 0; i < size; i++) {
        WCHAR letter = input[i];
        for (int c = 0; c < 27; c++) {
            if (letter == big_letters[c]) {
                input[i] = little_letters[c];
            }
        }
    }
}

int Function::wstrcmp(const wchar_t* str1, const wchar_t* str2)
{
    GetLowerLetters(const_cast<WCHAR*>(str1));
    GetLowerLetters(const_cast<WCHAR*>(str2));

    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            break;
        }
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

int Function::_strlen(const wchar_t* str1)
{
    int ret = 0;
    while (*str1) {
        str1++;
        ret++;
    }

    return ret;
}

void* Function::pGetProcAddress(void* moduleHandle, const char* functionName)
{
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)moduleHandle;
    PIMAGE_NT_HEADERS nt_header = (PIMAGE_NT_HEADERS)((char*)(moduleHandle) + dos_header->e_lfanew);

    if (dos_header->e_magic != IMAGE_DOS_SIGNATURE) {
        return 0;
    }
    if (nt_header->Signature != IMAGE_NT_SIGNATURE) {
        return 0;
    }

    PIMAGE_DATA_DIRECTORY exports = &nt_header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
    if (exports->Size) {
        PIMAGE_EXPORT_DIRECTORY export_dir = (PIMAGE_EXPORT_DIRECTORY)((char*)(moduleHandle) + exports->VirtualAddress);
        DWORD* name_rvas = (DWORD*)((char*)(moduleHandle) + export_dir->AddressOfNames);
        DWORD* func_addrs = (DWORD*)((char*)(moduleHandle) + export_dir->AddressOfFunctions);
        WORD* ordinals = (WORD*)((char*)(moduleHandle) + export_dir->AddressOfNameOrdinals);
        for (DWORD i = 0; i < export_dir->NumberOfNames; i++)
        {
            const char* name = (const char*)((char*)(moduleHandle) + name_rvas[i]);
            if (Function::_strcmp(name, functionName) == 0)
            {
                DWORD ordinal = ordinals[i];
                DWORD func_addr = func_addrs[ordinal];
                return (void*)((char*)moduleHandle + func_addr);
            }
        }
    }

    return 0;
}

void* Function::pGetModuleHandle(const wchar_t* moduleName)
{
    PPEB pebPtr = GetPEB();
    PPEB_LDR_DATA ldr = (PPEB_LDR_DATA)pebPtr->Ldr;
    
    PLIST_ENTRY list_head = &(ldr->InMemoryOrderModuleList);
    PLIST_ENTRY list_entry = list_head->Flink;

    while (list_entry != list_head) {
        LDR_DATA_TABLE_ENTRY* module_entry = CONTAINING_RECORD(list_entry, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);

        if (!Function::wstrcmp(module_entry->FullDllName.Buffer, moduleName)) {
            return module_entry->DllBase;
        }

        list_entry = list_entry->Flink;
    }

    return nullptr;
}
