extern "C" void* GetStdOut();
extern "C" void* NtWriteFile(void* FileHandle, void* EVENT, void* ApcRoutine, void* apccontext, void* IoStatusBlock, void* buffer, unsigned int length, void* ByteOffset, void* key);

void print() {
    void* out_handle = GetStdOut();
    unsigned char io_status[30]{};
    char buf[] = "Hello World!\n";
    NtWriteFile(out_handle, nullptr, nullptr, nullptr, &io_status, reinterpret_cast<void*>(buf), sizeof(buf), nullptr, nullptr);
}

extern "C" void __cdecl haha_no_int_main_needed(void) {   
    print();
}

#ifdef _DEBUG
int main() {
    haha_no_int_main_needed();
}
#else
