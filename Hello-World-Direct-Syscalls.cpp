extern "C" void* GetStdOut();
extern "C" void* NtWriteFile(void* FileHandle, void* EVENT, void* ApcRoutine, void* apccontext, void* IoStatusBlock, void* buffer, unsigned int length, void* ByteOffset, void* key);

int main() {
    void* out_handle = GetStdOut();
    unsigned char io_status[30]{};
    char buf[] = "Hello World!\n";
    NtWriteFile(out_handle, nullptr, nullptr, nullptr, &io_status, reinterpret_cast<void*>(buf), sizeof(buf), nullptr, nullptr);
}