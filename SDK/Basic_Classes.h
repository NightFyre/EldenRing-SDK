#pragma once

/**
 * Name: Elden Ring
 * Version: ~
 * Engine: ~
*/

#pragma pack(push, 0x01)
namespace HEXINTON
{
	template<typename ElementType>
    class ElementArray
    {
    private:
        ElementType*    _data;
        void*           _last;

    public:
        ElementArray()
        {
            _data = nullptr;
            _last = nullptr;
        }
        
        int32_t Count()
        {
            uintptr_t startAddr = reinterpret_cast<uintptr_t>(_data);
            uintptr_t endAddr = reinterpret_cast<uintptr_t>(_last);
            auto size = endAddr - startAddr;
            return size / sizeof(void*);
        }

        ElementType* Data() { return _data; }
        ElementType* begin() { return _data; }
        ElementType* end() { return _data + Count(); }
        bool IsValidIndex(int32_t i) { return i < Count(); }
		ElementType& operator[](int32_t i) { return _data[i]; }
		const ElementType& operator[](int32_t i) const { return _data[i]; }
    };
}
#pragma pack(pop)