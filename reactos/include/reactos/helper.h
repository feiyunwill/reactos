#ifndef _HELPER_H
#define _HELPER_H
 
#define ROUNDUP(a,b)	((((a)+(b)-1)/(b))*(b))
#define ROUNDDOWN(a,b)	(((a)/(b))*(b))
#define ROUND_UP ROUNDUP
#define ROUND_DOWN ROUNDDOWN
#define PAGE_ROUND_DOWN(x) (((ULONG)x)&(~(PAGE_SIZE-1)))
#define PAGE_ROUND_UP(x) ( (((ULONG)x)%PAGE_SIZE) ? ((((ULONG)x)&(~(PAGE_SIZE-1)))+PAGE_SIZE) : ((ULONG)x) )
#define ABS_VALUE(V) (((V) < 0) ? -(V) : (V))
#define RtlRosMin(X,Y) (((X) < (Y))? (X) : (Y))
#define RtlRosMin3(X,Y,Z) (((X) < (Y)) ? RtlRosMin(X,Z) : RtlRosMin(Y,Z))
#define KEBUGCHECKEX(a,b,c,d,e) DbgPrint("KeBugCheckEx at %s:%i\n",__FILE__,__LINE__), KeBugCheckEx(a,b,c,d,e)
#define KEBUGCHECK(a) DbgPrint("KeBugCheck at %s:%i\n",__FILE__,__LINE__), KeBugCheck(a)
#define EXPORTED __declspec(dllexport)
#define IMPORTED __declspec(dllimport)
#define LIST_FOR_EACH(entry, head) \
   for(entry = (head)->Flink; entry != (head); entry = entry->Flink)
#define LIST_FOR_EACH_SAFE(tmp_entry, head, ptr, type, field) \
   for ((tmp_entry)=(head)->Flink; (tmp_entry)!=(head) && \
        ((ptr) = CONTAINING_RECORD(tmp_entry,type,field)) && \
        ((tmp_entry) = (tmp_entry)->Flink); )
#define OPTHDROFFSET(a) ((LPVOID)((BYTE *)a		     +	\
			 ((PIMAGE_DOS_HEADER)a)->e_lfanew    +	\
			 sizeof (IMAGE_NT_SIGNATURE)		     +	\
			 sizeof (IMAGE_FILE_HEADER)))
#define TAG(A, B, C, D) (ULONG)(((A)<<0) + ((B)<<8) + ((C)<<16) + ((D)<<24))
#define RVA(m, b) ((ULONG)b + m)
#endif
