#include "dyn_arr.h"

/// <summary>
/// ���������� ������. ������� ������������� �����, ����� ��� ����������.
/// </summary>
/// <param name="arr"></param>
/// <returns>���������� �������������� �� ������� ������.</returns>
dynIntArr posAndNegArrOrg(dynIntArr arr);

/// <summary>
/// ���������� ��� char ������� � ���� �� ������� 
/// a[0] b[0] a[1] b[1] ... a[A_LEN] b[A_LEN] b[A_LEN + 1] ... b[B_LEN]
/// </summary>
/// <param name="arrA">�������� arrA</param>
/// <param name="arrB">�������� arrB</param>
/// <returns>
/// ���������� �������������� ������
/// </returns>
dynCharArr stringUnite(dynCharArr arrA, dynCharArr arrB);