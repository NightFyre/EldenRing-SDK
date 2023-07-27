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
            auto dist = reinterpret_cast<uintptr_t>(_last) - reinterpret_cast<uintptr_t>(_data);
            return static_cast<int32_t>((dist / sizeof(void*)) - sizeof(char));
        }

		ElementType& operator[](int32_t i) { return _data[i]; }
		const ElementType& operator[](int32_t i) const { return _data[i]; }

        ElementType* Data() { return _data; }
        ElementType* begin() { return _data; }
        ElementType* end() { return _data + Count(); }
        bool IsValidIndex(int32_t i) { return i >= NULL && i < Count(); }
    };
}
#pragma pack(pop)