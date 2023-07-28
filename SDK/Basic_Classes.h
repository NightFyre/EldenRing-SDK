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
        int32_t Count()
        {
            auto dist = reinterpret_cast<uintptr_t>(_last) - reinterpret_cast<uintptr_t>(_data);
            return static_cast<int32_t>(dist / sizeof(void*));
        }

		ElementType& operator[](int32_t i) { return _data[i]; }
		const ElementType& operator[](int32_t i) const { return _data[i]; }

        void* LastEntry() { return _last; }
        ElementType* Data() { return _data; }
        ElementType* begin() { return _data; }
        ElementType* end() { return _data + Count(); }
        bool IsValidIndex(int32_t i) { return i >= NULL && i < Count(); }
        
        ElementArray() noexcept = default;
        ElementArray(ElementType* in, void* end) 
        { 
            _data = in;
            _last = end;
        }
    };

    //  Custom Debug View Array
    template<typename T>
    class DebugArray : public ElementArray<T>
    {
    private:
        int32_t     _count;

    public:

        size_t size() { return _count; }
        DebugArray(ElementArray<T> array) : ElementArray<T>(array.Data(), array.LastEntry()) { this->_count = this->Count(); }
    };
}
#pragma pack(pop)