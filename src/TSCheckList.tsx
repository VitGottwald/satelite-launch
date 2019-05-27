import * as React from 'react';

const {useState, useEffect} = React;

const checkList = ['BOOSTER', 'FIDO', 'GUIDANCE'];
const initialStatus = checkList.map(() => false);
const isChecked = (item: boolean) => item === true;
const flipItem = (index: number, status: Array<boolean>) =>
  status.map((item: boolean, i: number) =>
    i === index ? !item : item
  );

interface ICheckListProps {
  onChange(completed: boolean): void;
}

const CheckList = ({onChange}: ICheckListProps) => {
  const [status, setStatus] = useState(initialStatus);
  const completed = status.every(isChecked);

  useEffect(() => {
    onChange(completed);
  }, [onChange, completed]);

  return (
    <div className="info">
      {checkList.map((name, index) => (
        <CheckListItem
          key={index}
          text={name}
          checked={status[index]}
          onClick={() => setStatus(flipItem(index, status))}
        />
      ))}
    </div>
  );
};

const CheckListItem = ({
  checked,
  text,
  onClick,
}: {
  checked: boolean;
  text: string;
  onClick: () => void;
}) => {
  const ticked = checked ? 'ticked' : '';
  return (
    <div className={`box ${ticked}`} onClick={onClick}>
      <span /> {text}
    </div>
  );
};

export default CheckList;
