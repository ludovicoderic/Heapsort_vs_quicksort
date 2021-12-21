// Valderico Carratala Rizzo 48792178R


#include <unistd.h>
#include <iostream>
#include <math.h>
#include <iomanip>

size_t _STEPS_ = 0;
size_t _STEPS2_ = 0;

using namespace std;

//--------------------------------------------------------------
// Middle Quick Sort
void 
middle_QuickSort(int * v, long left, long right){
long i,j;
int pivot; 
	if (left<right){
		i=left; j=right;
		pivot=v[(i+j)/2];
		do{
            _STEPS_++;
			while (v[i]<pivot){
            _STEPS_++;
            i++;
            }
			while (v[j]>pivot){
            _STEPS_++;
            j--; 
            } 
			if (i<=j){ 
				swap(v[i], v[j]);
				i++; j--;
			}
		}while (i<=j);
		if (left < j)  middle_QuickSort(v,left,j);
		if (i < right) middle_QuickSort(v,i,right);
	}
    _STEPS_++;
}

//--------------------------------------------------------------                
//HEAPSORT
// Procedure sink used by Heapsort algorith
// Sink an element (indexed by i) in a tree to keep the heap property. n is the size of the heap. 

void sink(int *v, size_t n, size_t i)
{
size_t largest;
size_t l, r; //left and right child

do{
	_STEPS2_++;
   	largest = i;  // Initialize largest as root
    l = 2*i + 1;  // left = 2*i + 1
    r = 2*i + 2;  // right = 2*i + 2
 
    // Is left child larger than root?
    if (l < n && v[l] > v[largest])
        largest = l;
 
    // Is right child larger than largest so far
    if (r < n && v[r] > v[largest])
        largest = r;
 
    // If largest is still root then the process is done
    if (largest == i) break;
    
	// If not, swap new largest with current node i and repeat the process with childs. 
    swap(v[i], v[largest]);
 	i=largest;  
   } while (true);
}
 
//--------------------------------------------------------------                
// Heapsort algorithm (ascending sorting)
void heapSort(int *v, size_t n)
{
    // Build a MAX-HEAP with the input array
    for (size_t i = n / 2 - 1; i >= 0; i--){
		_STEPS2_++;
        sink(v, n, i);
		if (i==0) break; //as size_t is unsigned type
	}	

	// A this point we have a HEAP on the input array, let's take advantage of this to sort the array:
    // One by swap the first element, which is the largest (max-heap), with the last element of the vector and rebuild heap by sinking the new placed element on the begin of vector.  
    for (size_t i=n-1; i>0; i--)
    {
		_STEPS2_++;
		// Move current root to the end.
        swap(v[0], v[i]);
 		// Now largest element is at the end but do not know if the element just moved to the beginning is well placed, so a sink process is required.
		// Note that, at the same time, the HEAP size is reduced one element by one.
        sink(v, i, 0);
		// The procedure ends when HEAP has only one element, the lower of the input array
    }
}

int main(void){

	int * v, * v2, * v_volteado;
  
	size_t size;

    float pasos = 0, pasos2 = 0;

	srand(getpid());

	cout << "             RANDOM ARRAYS        SORTED ARRAYS      REVERSE SORTED ARRAYS"<<endl;
    cout << "Size      QuickSort  HeapSort  QuickSort  HeapSort  QuickSort  HeapSort"<<endl;

	for (int exp = 15; exp <= 20; exp++){
		size = (size_t) powl(2,exp);
		v = new int [size];
        v2 = new int [size];
        v_volteado = new int[size];

		if (v){
            cout << size << "    " << std::flush;
            // Vectores con contenido aleatorio
            for(int i=0 ; i<30 ; i++){
                //RELLENA EL VECTOR ALEATORIAMENTE
                for (size_t j = 0; j < size; j++){
                    v[j] = rand(); 
                    v2[j] = v[j];
                }
                middle_QuickSort(v,0,size-1);
                heapSort(v2,size);
            }
            pasos = (float)(_STEPS_/30)/1000000;
            pasos2 = (float)(_STEPS2_/30)/1000000;

            if(exp==15 or exp==16)
                cout<<"  ";
            else if(exp==17 or exp==17)
                cout<<" ";

            cout<<setprecision(3)<<pasos<<"      ";
            cout<<setprecision(3)<<pasos2<<"      ";
            _STEPS_ = _STEPS2_ = pasos = pasos2 = 0;
            
            // Vectores ordenados de manera creciente
            for(int i=0 ; i<30 ; i++){
                middle_QuickSort(v,0,size-1);
                heapSort(v,size);
            }
            pasos = (float)(_STEPS_/30)/1000000;
            pasos2 = (float)(_STEPS2_/30)/1000000;

            cout<<setprecision(3)<<pasos<<"      ";
            cout<<setprecision(3)<<pasos2<<"      ";
            _STEPS_ = _STEPS2_ = pasos = pasos2 = 0;

            // Vectores ordenados de manera decreciente
            // Le damos la vuelta al vector
            for(size_t k = 0; k<size ; k++){
                v_volteado[k] = v[size-k];
            }
            
            for(int i=0 ; i<30 ; i++){
                middle_QuickSort(v_volteado,0,size-1);
                heapSort(v_volteado,size);
            }
            pasos = (float)(_STEPS_/30)/1000000;
            pasos2 = (float)(_STEPS2_/30)/1000000;

            cout<<setprecision(3)<<pasos<<"      ";
            cout<<setprecision(3)<<pasos2<<"      "<<endl;
            _STEPS_ = _STEPS2_ = pasos = pasos2 = 0;
		}//if(v)
	}
}




