import { useEffect, useState } from "react";
import { getData, resetData } from "../services/data.services";

interface Data {
  id: string;
  status: string;
}

const Monitor = () => {
  const [data, setData] = useState({} as Data);
  const [audio] = useState(new Audio("alarm.mp3"));

  useEffect(() => {
    const interval = setInterval(() => {
      getData().then((res) => {
        if (data.status !== res.status) {
          setData(res);
        } else {
          return;
        }
      });
    }, 5000);
    return () => clearInterval(interval);
  }, [data]);

  useEffect(() => {
    if (data.status === "bahaya") {
      audio.play();
      audio.loop = true;
    } else {
      audio.pause();
    }
  }, [data, audio]);

  const handleOnClick = () => {
    resetData();
  };

  return (
    <div
      className={`w-screen ${
        data.status === "bahaya" ? "bg-red-500" : "bg-green-500"
      }`}
    >
      <div className="container mx-auto h-screen flex flex-col justify-center items-center gap-10">
        <h1 className="text-5xl font-semibold">Status</h1>
        {data.status === "bahaya" ? (
          <>
            <p className="text-5xl font-semibold">Bahaya</p>
            <button onClick={handleOnClick}>Reset</button>
          </>
        ) : (
          <p className="text-5xl font-semibold">Aman</p>
        )}
      </div>
    </div>
  );
};

export default Monitor;
