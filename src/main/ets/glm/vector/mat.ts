import { float, valuetype } from './nvec'
type row = 2 | 3 | 4;
type column = 2 | 3 | 4;

interface mat<TType extends valuetype, TRow extends row, TColumn extends column> {
  element: TType;
  row: TRow;
  column: TColumn;
}

class mat2 implements mat<float, 2, 2> {
  element: Float32Array;
  row: 2;
  column: 2;

}