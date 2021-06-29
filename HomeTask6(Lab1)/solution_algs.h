#include "dyn_arr.h"

/// <summary>
/// Организует массив. Сначала отрицательные числа, потом все оставшиеся.
/// </summary>
/// <param name="arr"></param>
/// <returns>Возварщает сформированный по правилу массив.</returns>
dynIntArr posAndNegArrOrg(dynIntArr arr);

/// <summary>
/// Объединяет два char массива в один по правилу 
/// a[0] b[0] a[1] b[1] ... a[A_LEN] b[A_LEN] b[A_LEN + 1] ... b[B_LEN]
/// </summary>
/// <param name="arrA">описание arrA</param>
/// <param name="arrB">описание arrB</param>
/// <returns>
/// Возвращает сформированный массив
/// </returns>
dynCharArr stringUnite(dynCharArr arrA, dynCharArr arrB);