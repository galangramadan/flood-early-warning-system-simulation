import axios from "axios";

export const getData = async () => {
  const { data } = await axios.get(`${import.meta.env.VITE_API_URL}`);
  if (data) {
    return data;
  }
};
